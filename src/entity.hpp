#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <ncurses.h>

class entity {
    protected:
        char img;
        int xPos;
        int yPos;
    public:
        entity(char img);

        int getX();
        int getY();

        void setYX(int y, int x, WINDOW* win);

        void shiftPos(int xShift, int yShift, WINDOW* win);
};

#endif
