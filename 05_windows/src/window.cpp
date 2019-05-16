#include "window.h"

Window::Window(const WindowSpecification& spec)
	: m_spec(spec), m_new_pos(spec.pos)
{
	redraw();
}

Window::Window()
{
}

Window::~Window()
{
}

void Window::redraw()
{
	int y, x,
	    h, w;

	y = m_spec.pos.y;
	x = m_spec.pos.x;
	h = m_spec.pos.h;
	w = m_spec.pos.w;

	for (int cy = y; cy <= y + h; cy+=h)
		for (int cx = x; cx <= x + w; cx++)
			mvaddch(cy, cx, ' ');
	for (int cy = y; cy <= y + h; cy++)
		for (int cx = x; cx <= x + w; cx+=w)
			mvaddch(cy, cx, ' ');

	m_spec.pos = m_new_pos;
	y = m_spec.pos.y;
	x = m_spec.pos.x;
	h = m_spec.pos.h;
	w = m_spec.pos.w;

	mvaddch(y,     x,     m_spec.border.tl);
	mvaddch(y,     x + w, m_spec.border.tr);
	mvaddch(y + h, x,     m_spec.border.bl);
	mvaddch(y + h, x + w, m_spec.border.br);
	mvhline(y,     x + 1, m_spec.border.ts, w - 1);
	mvhline(y + h, x + 1, m_spec.border.bs, w - 1);
	mvvline(y + 1, x,     m_spec.border.ls, h - 1);
	mvvline(y + 1, x + w, m_spec.border.rs, h - 1);
}

void Window::refresh()
{
	int y, x,
	    h, w;

	y = m_spec.pos.y;
	x = m_spec.pos.x;
	h = m_spec.pos.h;
	w = m_spec.pos.w;

	mvaddch(y,     x,     m_spec.border.tl);
	mvaddch(y,     x + w, m_spec.border.tr);
	mvaddch(y + h, x,     m_spec.border.bl);
	mvaddch(y + h, x + w, m_spec.border.br);
	mvhline(y,     x + 1, m_spec.border.ts, w - 1);
	mvhline(y + h, x + 1, m_spec.border.bs, w - 1);
	mvvline(y + 1, x,     m_spec.border.ls, h - 1);
	mvvline(y + 1, x + w, m_spec.border.rs, h - 1);
}

void Window::move(char dir)
{
	switch (dir) {
		case 'h': if (m_new_pos.x > 0)                       m_new_pos.x--; break;
		case 'j': if (m_new_pos.y < LINES - m_new_pos.h - 1) m_new_pos.y++; break;
		case 'k': if (m_new_pos.y > 0)                       m_new_pos.y--; break;
		case 'l': if (m_new_pos.x < COLS  - m_new_pos.w - 1) m_new_pos.x++; break;
	}
}

void Window::resize(char dir)
{
	switch (dir) {
		case 'H': if (m_new_pos.w > 2)                       m_new_pos.w--; break;
		case 'J': if (m_new_pos.y + m_new_pos.h < LINES - 1) m_new_pos.h++; break;
		case 'K': if (m_new_pos.h > 2)                       m_new_pos.h--; break;
		case 'L': if (m_new_pos.x + m_new_pos.w < COLS - 1)  m_new_pos.w++; break;
	}
}
