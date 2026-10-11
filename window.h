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
		printw("Not a big enough screen resolution.\nEnsure 40 cols x 30 rows are avaliable.\n");
		getch();
	}
	return state_bad;
}
