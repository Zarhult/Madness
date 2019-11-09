#include <ncurses.h>
#include <stdlib.h>
#include "drawGrid.hpp"

using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();


    endwin();
    return 0;
}