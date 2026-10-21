#include "panel.h"
#include <ncurses.h>

static PANEL stack[16];
static int stack_size = 0;

PANEL *mpush(PANEL panel) {
	if (stack_size >= 16) return NULL;

	stack[stack_size++] = panel;
	PANEL *np = &stack[stack_size-1];

	np->_window = newwin(np->h, np->w, np->y, np->x);
	keypad(np->_window, TRUE);

	if (np->on_push) np->on_push(np);

	return np;
}

void mpop() {
	if (!stack_size) return;
	delwin(stack[stack_size-1]._window);
	touchwin(stdscr); // all layers must be redrawn
	stack_size--;
}

void mclear() {
	while (stack_size > 0) mpop(); // clear
}


void mdraw(void) {
	for (int i = 0; i < stack_size; i++) {
		PANEL *p = &stack[i];
		werase(p->_window); // black background
		box(p->_window, 0, 0);
		if (p->title)
			mvwprintw(p->_window, 0, 2, " %s ", p->title);
		wnoutrefresh(p->_window); // queue refresh
	}
}
