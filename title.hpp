#include <ncurses.h>
#include <stdlib.h>
#include <vector>

void printTitle(){
    int row;
    int col;
    getmaxyx(stdscr, row, col);

    int val = col * (0.75) - 20;
    mvprintw(2 , val, "  __  __           _                     ");
    mvprintw(3 , val, " |  \\/  |         | |                    ");
    mvprintw(4 , val, " | \\  / | __ _  __| |_ __   ___  ___ ___ ");
    mvprintw(5 , val, " | |\\/| |/ _' |/ _` | '_ \\ / _ \\/ __/ __|");
    mvprintw(6 , val, " | |  | | (_| | (_| | | | |  __/\\__ \\__ \\");
    mvprintw(7 , val, " |_|  |_|\\__,_|\\__,_|_| |_|\\___||___/___/");
    mvprintw(8 , val, "----------------------------------------");
}
