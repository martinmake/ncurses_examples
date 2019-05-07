#ifndef _NCURSESTUI_WINDOW_H_
#define _NCURSESTUI_WINDOW_H_

#include <ncurses.h>

class Window
{
	private:
		WINDOW* win;

	public:
		Window(int height, int width, int y, int x);
		Window(void);
		~Window(void);

		void redraw(int height, int width, int y, int x);

	private:
		void destroy_win(void);
		void create_win(int height, int width, int y, int x);
};

#endif
