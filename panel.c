#include "panel.h"
#include <ncurses.h>

static PANEL stack[16];
static int stack_size = 0;

PANEL *mpush(PANEL panel) {
	stack[stack_size++] = panel;
	PANEL *np = &stack[stack_size-1];

	if (np->on_push) np->on_push(np);

	return np;
}

void mpop() {
	stack_size--;
}

void mclear() {
	stack_size = 0;
}

void mdraw() {
	for (int i = 0; i < stack_size; i++) {
		// draw logic
	}
}
