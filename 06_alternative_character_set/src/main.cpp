#include <ncurses.h>
#include <stdlib.h>
#include <signal.h>

static void finish(int sig)
{
	endwin();

	(void) sig;

	exit(0);
}

int main(void)
{
	signal(SIGINT, finish);
	initscr();
	curs_set(0);

	printw("Upper left corner        "); addch(ACS_ULCORNER); addch('\n');
	printw("Lower left corner        "); addch(ACS_LLCORNER); addch('\n');
	printw("Lower right corner       "); addch(ACS_LRCORNER); addch('\n');
	printw("Tee pointing right       "); addch(ACS_LTEE);     addch('\n');
	printw("Tee pointing left        "); addch(ACS_RTEE);     addch('\n');
	printw("Tee pointing up          "); addch(ACS_BTEE);     addch('\n');
	printw("Tee pointing down        "); addch(ACS_TTEE);     addch('\n');
	printw("Horizontal line          "); addch(ACS_HLINE);    addch('\n');
	printw("Vertical line            "); addch(ACS_VLINE);    addch('\n');
	printw("Large Plus or cross over "); addch(ACS_PLUS);     addch('\n');
	printw("Scan Line 1              "); addch(ACS_S1);       addch('\n');
	printw("Scan Line 3              "); addch(ACS_S3);       addch('\n');
	printw("Scan Line 7              "); addch(ACS_S7);       addch('\n');
	printw("Scan Line 9              "); addch(ACS_S9);       addch('\n');
	printw("Diamond                  "); addch(ACS_DIAMOND);  addch('\n');
	printw("Checker board (stipple)  "); addch(ACS_CKBOARD);  addch('\n');
	printw("Degree Symbol            "); addch(ACS_DEGREE);   addch('\n');
	printw("Plus/Minus Symbol        "); addch(ACS_PLMINUS);  addch('\n');
	printw("Bullet                   "); addch(ACS_BULLET);   addch('\n');
	printw("Arrow Pointing Left      "); addch(ACS_LARROW);   addch('\n');
	printw("Arrow Pointing Right     "); addch(ACS_RARROW);   addch('\n');
	printw("Arrow Pointing Down      "); addch(ACS_DARROW);   addch('\n');
	printw("Arrow Pointing Up        "); addch(ACS_UARROW);   addch('\n');
	printw("Board of squares         "); addch(ACS_BOARD);    addch('\n');
	printw("Lantern Symbol           "); addch(ACS_LANTERN);  addch('\n');
	printw("Solid Square Block       "); addch(ACS_BLOCK);    addch('\n');
	printw("Less/Equal sign          "); addch(ACS_LEQUAL);   addch('\n');
	printw("Greater/Equal sign       "); addch(ACS_GEQUAL);   addch('\n');
	printw("Pi                       "); addch(ACS_PI);       addch('\n');
	printw("Not equal                "); addch(ACS_NEQUAL);   addch('\n');
	printw("UK pound sign            "); addch(ACS_STERLING); addch('\n');

	refresh();
	getch();
	endwin();

	return 0;
}
