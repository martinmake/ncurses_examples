#include <ncurses.h>
#include <ctype.h>

int main(void)
{
	initscr();            // start curses mode
	raw();                // disable line buffering
	keypad(stdscr, TRUE); // enable special keys
	noecho();             // don't echo back when typing

	for (int c = 0; c != 'q'; ) {
		c = getch();

		if (isprint(c)) {
			printw("YOU ENTERED: ");
			addch(c | A_BOLD);
			addch('\n');
		} else {
			printw("YOU ENTERED: ");
			attron(A_UNDERLINE);
			addstr("NON-PRINTABLE CHARACTER\n");
			attroff(A_UNDERLINE);
		}

		refresh();
	}

	endwin();
	return 0;
}
