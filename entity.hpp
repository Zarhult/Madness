#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

class entity {
    protected:
        char img;
        int xPos;
        int yPos;
    public:
        entity(char img) : img(img) {};

        int getX() {
            return this->xPos;
        }

        int getY() {
            return this->yPos;
        }

        void setYX(int y, int x, WINDOW* win) {
            int row;
            int col;
            getmaxyx(win, row, col);
            if (x < col && x > 1 && y < row - 1 && y > 0) { //don't let the player leave the window
                if (this->yPos != 0) { //don't do this when creating the player
                    mvaddch(this->yPos, this->xPos, '+');
                }

                this->xPos = x;
                this->yPos = y;
                mvaddch(y, x, img);
            }
        }

        void shiftPos(int xShift, int yShift, WINDOW* win) {
            int row;
            int col;
            getmaxyx(win, row, col);
            int newXPos = this->xPos + xShift;
            int newYPos = this->yPos + yShift;
            if (newXPos < col && newXPos > 1 && newYPos < row - 1 && newYPos > 0) { //don't let the player leave the window
                this->setYX(newYPos, newXPos, win);
            }
        }
};

#endif