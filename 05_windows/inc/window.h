#ifndef _NCURSESTUI_WINDOW_H_
#define _NCURSESTUI_WINDOW_H_

#include <ncurses.h>

struct WindowBorder
{
	chtype ls, rs, ts, bs,
	       tl, tr, bl, br;
};

struct WindowPosition
{
	int x, y,
	    w, h;
};

struct WindowSpecification
{
	WindowBorder   border;
	WindowPosition pos;

	WindowSpecification()
	{
		pos.h     =  2;
		pos.w     =  2;
		pos.y     =  0;
		pos.x     =  0;
		border.ls = '|';
		border.rs = '|';
		border.bs = '-';
		border.ts = '-';
		border.tl = '+';
		border.tr = '+';
		border.bl = '+';
		border.br = '+';
	}
};

class Window
{
	private:
		WindowSpecification m_spec;
		WindowPosition      m_new_pos;

	public:
		Window(const WindowSpecification& spec);
		Window(void);
		~Window(void);

		void redraw(void);
		void refresh(void);

		void move(char dir);
		void resize(char dir);
};

#endif
