#include <ncurses.h>
#include <form.h>
#include <stdlib.h>
#include <signal.h>
#include <dialog.h>

static void finish(int sig)
{
	endwin();

	(void) sig;

	exit(0);
}

int main(void)
{
	uint8_t field_count = 3;
	FIELD* fields[field_count];
	FORM*  form;

	signal(SIGINT, finish);
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	for (uint8_t i = 0; i < field_count - 1; i++)
		fields[i] = new_field(1, 10, 4 + i * 2, 18, 0, 0);
	fields[field_count - 1] = NULL;

	set_field_back(fields[0], A_UNDERLINE);
	field_opts_off(fields[0], O_AUTOSKIP);

	set_field_back(fields[1], A_UNDERLINE);
	field_opts_off(fields[1], O_AUTOSKIP);

	form = new_form(fields);
	post_form(form);
	refresh();

	mvprintw(4, 10, "KEY1 = ");
	mvprintw(6, 10, "KEY2 = ");
	refresh();

	for (int c = getch(); c != ESC && c != 'q'; c = getch()) {
		switch (c) {
			case 'k':
				form_driver(form, REQ_NEXT_FIELD);
				form_driver(form, REQ_END_LINE);
				break;
			case 'j':
				form_driver(form, REQ_PREV_FIELD);
				form_driver(form, REQ_END_LINE);
				break;
			default:
				form_driver(form, c);
				break;
		}
	}

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);
	free_field(fields[1]);

	refresh();
	endwin();

	return 0;
}
