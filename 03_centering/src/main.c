#include <ncurses.h>
#include <string.h>

#define PROMPT "ENTER A STRING: "

int main(void)
{
	char str[64];
	int rows, cols;

	initscr();
	getmaxyx(stdscr, rows, cols);

	mvprintw(rows / 2,     (cols - strlen(PROMPT)) / 2, PROMPT);
	getstr(str);
	mvprintw(LINES - 2, 0, "YOU ENTERED: ");
	attrset(A_BLINK | A_BOLD | A_STANDOUT);
	addstr(str);

	getch();
	endwin();
	return 0;
}
