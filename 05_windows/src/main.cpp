#include <ncurses.h>

#include "window.h"

#define Y      ((LINES - height) / 2)
#define X      ((COLS  - width ) / 2)
#define HEIGHT 3
#define WIDTH  10

int main(void)
{
	int y,      x;
	int height, width;
	int c = '\0';

	initscr();
	cbreak();
	noecho();

	height = HEIGHT;
	width  = WIDTH;
	y      = Y;
	x      = X;

	Window win = Window(height, width, y, x);
	while (c != '\n') {
		switch (c) {
			case 'h': if (x > 0)              x--; break;
			case 'j': if (y < LINES - height) y++; break;
			case 'k': if (y > 0)              y--; break;
			case 'l': if (x < COLS - width)   x++; break;
		}

		win.redraw(height, width, y, x);
		c = getch();
	}

	while ((c = getch()) == '\n') {}
	while (c != '\n') {
		switch (c) {
			case 'h': if (width  > 3)         width --; break;
			case 'j': if (y + height < LINES) height++; break;
			case 'k': if (height > 3)         height--; break;
			case 'l': if (x + width  < COLS)  width ++; break;
		}

		win.redraw(height, width, y, x);
		c = getch();
	}


	while ((c = getch()) != 'q') {}

	endwin();
	return 0;
}
