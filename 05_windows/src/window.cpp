#include "window.h"

Window::Window(int height, int width, int y, int x)
{
	create_win(height, width, y, x);
}

Window::Window()
{
}

Window::~Window()
{
	destroy_win();
}

void Window::redraw(int height, int width, int y, int x)
{
	destroy_win();
	create_win(height, width, y, x);
}

void Window::destroy_win(void)
{
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(win);
	delwin(win);
}

void Window::create_win(int height, int width, int y, int x)
{
	win = newwin(height, width, y, x);
	box(win, 0, 0);
	wrefresh(win);
}
