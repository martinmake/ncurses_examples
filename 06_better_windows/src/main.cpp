#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <vector>

#include "window.h"

static void finish(int sig)
{
	endwin();

	(void) sig;

	exit(0);
}

int main(void)
{
	int c = '\0';
	std::vector<Window> wins;
	WindowSpecification win_spec;

	signal(SIGINT, finish);
	initscr();
	cbreak();
	noecho();
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	refresh();

	while (1) {
		wins.push_back(Window(win_spec));

		while ((c = getch()) != '\n') {
			wins.back().move(c);
			wins.back().redraw();
			for (Window& w : wins)
				w.refresh();
		}

		while ((c = getch()) != '\n') {
			wins.back().resize(c);
			wins.back().redraw();
			for (Window& w : wins)
				w.refresh();
		}
	}

	endwin();
	return 0;
}
