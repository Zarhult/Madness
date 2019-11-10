#include <ncurses.h>
#include <stdlib.h>
#include <vector>

void printtitle(){
    int row;
    int col;
    getmaxyx(stdscr, row, col);

    mvprintw(2 , col- (3*col/8) +2,"  __  __           _                     ");
    mvprintw(3 , col- (3*col/8) +2," |  \\/  |         | |                    ");
    mvprintw(4 , col- (3*col/8) +2," | \\  / | __ _  __| |_ __   ___  ___ ___ ");
    mvprintw(5 , col- (3*col/8) +2," | |\\/| |/ _' |/ _` | '_ \\ / _ \\/ __/ __|");
    mvprintw(6 , col- (3*col/8) +2," | |  | | (_| | (_| | | | |  __/\\__ \\__ \\");
    mvprintw(7 , col- (3*col/8) +2," |_|  |_|\\__,_|\\__,_|_| |_|\\___||___/___/");
    mvprintw(8 , col- (3*col/8) +2,"----------------------------------------");
}
