#include <ncurses.h>
#include <window.h>

int main() {
	initscr();
	wscheck();
	endwin();
}
