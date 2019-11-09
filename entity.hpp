#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

class entity {
    protected:
        char img;
        int xPos;
        int yPos;
    public:
        entity() {};

        void setXY(int x, int y, WINDOW* win) {
            mvaddch(this->yPos, this->xPos, '+');

            this->xPos = x;
            this->yPos = y;
            mvaddch(y, x, img);
        }
};

#endif