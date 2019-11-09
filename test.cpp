#include <ncurses.h>
#include <stdlib.h>

using namespace std;

int main() {
	initscr();
	printw("helloworld");
	refresh();
	getch();
	endwin();

	return 0;
}	
