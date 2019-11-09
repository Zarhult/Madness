#include <ncurses.h>
#include <stdlib.h>
#include "drawGrid.hpp"

using namespace std;

int main() {
    initscr(); //initialize
    raw(); //don't wait for the user to hit enter
    noecho(); //don't show the user's input
    keypad(stdscr, TRUE); //enable function keys like arrow keys

    int row; //initialize useful variables
    int col;
    getmaxyx(stdscr, row, col);
    int ch;

    WINDOW *win1;
    win1 = newwin(row, col/2 - 1, 0, 0);
    box(win1, 0, 0);
    WINDOW *win2;
    win2 = newwin(row, col/2 - 1, 0, col / 2);
    box(win2, 0, 0);
    refresh();

    wrefresh(win1);
    wrefresh(win2);

    for (int x = 1; x <= row; ++x) {
        for (int y = 1; y <= col; ++y) {
            mvaddch(y, x, '+');
        }
    }


    getch();
    endwin(); //end
    return 0;
}