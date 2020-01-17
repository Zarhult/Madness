#include "cultist.hpp"
#include <string.h>
#include <stdlib.h>

void cultist::event(WINDOW* win) { //window is stdscr!!
    int row;
    int col;
    getmaxyx(win, row, col);

    mvprintw(12, col * (0.75) - strlen(alertMsg)/2, alertMsg);
    mvprintw(13, col * (0.75)  - 4, "You died.");
    mvprintw(14, col * (0.75) - 11, "Press any key to exit.");
    getch();
    endwin();
    std::exit(0);
    //mvprintw(10, col * (0.75), descriptionMsg);
}
