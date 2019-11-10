#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include "drawGrid.hpp"
#include "mob.hpp"
#include "player.hpp"

using namespace std;

void randMob(WINDOW*);
void refreshGridEntities(vector<entity*> entities);

int main() {
    initscr(); //initialize
    cbreak(); //don't wait for the user to hit enter
    noecho(); //don't show the user's input
    keypad(stdscr, TRUE); //enable function keys like arrow keys
    curs_set(0); //hide cursor

    int row; //initialize useful variables
    int col;
    getmaxyx(stdscr, row, col);
    int ch;

    WINDOW *win1; //set up play field and info window
    win1 = newwin(row, col/2 - 1, 0, 1);
    box(win1, 0, 0);
    WINDOW *win2;
    win2 = newwin(row, col/2 - 1, 0, col/2);
    box(win2, 0, 0);
    refresh();
    wrefresh(win1);
    wrefresh(win2);

    for (int x = 2; x <= col/2 - 2; ++x) { //initialize grid with default spaces (+)
        for (int y = 1; y <= row - 2; ++y) {
            mvaddch(y, x, '+');
        }
    }

    //initialize player
    player* plyr = new player;
    plyr->setYX(row/2, (col/2-1)/2, win1);

    while(ch = getch()) { //main loop
        switch(ch) {
            case KEY_LEFT:
                plyr->shiftPos(-1, 0, win1);
            case KEY_RIGHT:
                plyr->shiftPos(1, 0, win1);
            case KEY_UP:
                plyr->shiftPos(0, 1, win1);
            case KEY_DOWN:
                plyr->shiftPos(0, 1, win1);
        }
    }

    getch();
    endwin(); //end
    return 0;
}

void randMob(WINDOW* win) {
    int row;
    int col;
    getmaxyx(win, row, col);

    int x = rand() % col;
    int y = rand() % row;
}