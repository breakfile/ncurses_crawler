#include "panel.h"

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
