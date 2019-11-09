#include <ncurses.h>
#include <stdlib.h>
#include "drawGrid.hpp"

using namespace std;

int main() {
    initscr(); //initialize
    cbreak(); //don't wait for the user to hit enter
    noecho(); //don't show the user's input

    wrefresh(stdscr);
    int ch = getch();

    endwin(); //end
    return 0;
}