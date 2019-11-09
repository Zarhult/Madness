#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

class entity {
    protected:
        char img;
        int xPos;
        int yPos;
    public:
        entity(char img) : img(img) {};

        void setYX(int y, int x, WINDOW* win) {
            mvaddch(this->yPos, this->xPos, '+');

            this->xPos = x;
            this->yPos = y;
            mvaddch(y, x, img);
        }
};

#endif