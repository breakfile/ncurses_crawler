#pragma once

typedef struct panel {
	int x, y, w, h, sel;
	char *buttons[32]; // text
	void (*functions[32])(); // on pressed
	void (*on_push)(struct panel*);
} PANEL;

PANEL *mpush(PANEL panel);
void mpop();
void mclear();
