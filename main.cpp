#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include "mob.hpp"
#include "player.hpp"
#include "title.hpp"

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
    //box(win1, 0, 0);
    WINDOW *win2;
    win2 = newwin(row, col/2 - 1, 0, col/2);
    //box(win2, 0, 0);
    wrefresh(win1);
    wrefresh(win2);

    printTitle();
    for (int x = 2; x <= col/2 - 2; ++x) { //initialize grid with default spaces (+)
        for (int y = 1; y <= row - 2; ++y) {
            mvaddch(y, x, '+');
        }
    }

    //initialize player and vector of mobs
    std::vector<mobBase*> mobs;
    player* plyr = new player;
    plyr->setYX(row/2, (col/2-1)/2, win1);

    while(ch = getch()) { //main loop
        switch(ch) {
            case KEY_LEFT:
                plyr->shiftPos(-1, 0, win1);
                break;
            case KEY_RIGHT:
                plyr->shiftPos(1, 0, win1);
                break;
            case KEY_UP:
                plyr->shiftPos(0, -1, win1);
                break;
            case KEY_DOWN:
                plyr->shiftPos(0, 1, win1);
                break;
        }
        for (int i = 0; i < mobs.size(); ++i) {
            if (mobs.at(i)->getX() == plyr->getX() && mobs.at(i)->getY() == plyr->getY()) {
                mobs.at(i)->event(stdscr);
            }
        }

        int spawnMob = rand() % 2; //1/2 chance of spawn per turn
        mobBase* newMob;
        if (spawnMob == 0) {
            newMob = new cultist; //FIXME: make this a random mob
            mobs.push_back(newMob);
            int xPos = rand() % row;
            int yPos = rand() % col/2-1;
            newMob->setYX(xPos, yPos, win1);
        }

        refresh(); //redraw the grid
        wrefresh(win1);
        wrefresh(win2);
    }

    getch();
    endwin(); //end
    return 0;
}