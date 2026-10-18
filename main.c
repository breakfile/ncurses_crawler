#include <ncurses.h>
#include "window.h"
#include <unistd.h>
#include "actor.h"

#define FRAME_WAIT 100000 // 10fps

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);

	if (wscheck()) // initial window check
		goto cleanup;

	timeout(0); // getch doesn't block input
	int ch; // last keypress, default to ERR
	int running = 1;

	while (running) {
		ch = getch(); // get input, wont block
		if (ch == 'q')
			running = 0; // quit if key is q

		update_actors(ch);
		
		erase(); // clear screen, begin drawing

		draw_actors();

		refresh(); // put screen changes, end drawing

		usleep(FRAME_WAIT); // wait until next frame
	}

	cleanup:
		endwin();
		return 0;
}
