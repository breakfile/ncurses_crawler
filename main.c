#include <ncurses.h>
#include <window.h>
#include <unistd.h>

#define FRAME_WAIT 100000 // 10fps

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	wscheck(); // initial window check
	
	timeout(0); // getch doesn't block input
	int ch; // last keypress, default to ERR
	int running = 1;

	while (running) {
		ch = getch(); // wont block
		if (ch == 'q')
			running = 0;
		
		erase(); // clear screen, begin drawing
		refresh(); // put screen changes, end drawing

		usleep(FRAME_WAIT);
	}

	endwin();
	return 0;
}
