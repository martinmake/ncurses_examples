#include <ncurses.h>
#include <signal.h>
#include <ctype.h>
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
	curs_set(0);
	attron(COLOR_PAIR(1));

	while (1) {
		wins.push_back(Window(win_spec));

		while ((c = getch()) != '\n') {
			if (islower(c))
				wins.back().move(c);
			else
				wins.back().resize(c);

			wins.back().redraw();
			for (Window& w : wins)
				w.refresh();
		}
	}

	endwin();
	return 0;
}
