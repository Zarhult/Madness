#include <ncurses.h>
#include <stdlib.h>
#include "drawGrid.hpp"

using namespace std;

int main() {
    initscr(); //initialize
    raw(); //don't wait for the user to hit enter
    noecho(); //don't show the user's input
    keypad(stdscr, TRUE); //enable function keys like arrow keys

    const char* ch = getch();
    mvprintw(10, 10, ch);
    refresh();

    getch();
    endwin(); //end
    return 0;
}