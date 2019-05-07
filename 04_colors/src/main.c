#include <ncurses.h>

#define COLOR_INDEX 1
#define Y           1
#define X           1

int main(void)
{
	initscr();
	start_color();

	init_pair(COLOR_INDEX, COLOR_CYAN, COLOR_BLACK);
	mvprintw(Y, X, "A LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOONG STRING");
	mvchgat(Y, X, -1, A_BLINK | A_BOLD, COLOR_INDEX, NULL);
	move(0, 0);

	getch();
	endwin();
	return 0;
}
