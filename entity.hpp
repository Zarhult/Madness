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
            int row;
            int col;
            getmaxyx(win, row, col);
            if (x < col && x > 0 && y < row && y > 0) { //don't let the player leave the window
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
            if (newXPos < col && newXPos > 0 && newYPos < row && newYPos > 0) { //don't let the player leave the window
                mvaddch(this->yPos, this->xPos, '+');
                
                this->xPos = newXPos;
                this->yPos = newYPos;
                mvaddch(newYPos, newXPos, img);
            }
        }
};

#endif