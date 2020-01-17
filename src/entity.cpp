#include "entity.hpp"

entity::entity(char img) : img(img) {};

int entity::getX() {
    return this->xPos;
}

int entity::getY() {
    return this->yPos;
}

void entity::setYX(int y, int x, WINDOW* win) {
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

void entity::shiftPos(int xShift, int yShift, WINDOW* win) {
    int row;
    int col;
    getmaxyx(win, row, col);
    int newXPos = this->xPos + xShift;
    int newYPos = this->yPos + yShift;
    if (newXPos < col && newXPos > 1 && newYPos < row - 1 && newYPos > 0) { //don't let the player leave the window
	this->setYX(newYPos, newXPos, win);
    }
}
