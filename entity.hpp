#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

class entity {
    protected:
        int xPos;
        int yPos;
    public:
        entity() {};

        void setX(int x) {
            this->xPos = x;
        }
        void setY(int y) {
            this->yPos = y;
        }
};

#endif