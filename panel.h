#pragma once

#include <ncurses.h>
typedef struct panel {
	char *title;
	int x, y, w, h, sel;
	char *buttons[32]; // text
	void (*functions[32])(); // on pressed
	void (*on_push)(struct panel*);
	WINDOW *_window;
} PANEL;

PANEL *mpush(PANEL panel);
void mpop();
void mclear();

void mdraw();
