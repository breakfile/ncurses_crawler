#include <ncurses.h>

#define MAX_ROWS 30
#define MAX_COLS 40

// Check window size
static inline int wscheck() {
	int row, col;
	int state_bad = 0;
	getmaxyx(stdscr, row, col);
	if (row < MAX_ROWS)
		state_bad = 1;
	if (col < MAX_COLS)
		state_bad = 1;
	if (state_bad) {
		printw("Not a big enough screen resolution.\nEnsure %d cols x %d rows are avaliable.\n", MAX_COLS, MAX_ROWS);
		getch();
	}
	return state_bad;
}
