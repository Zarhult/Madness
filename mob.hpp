#ifndef __MOB_HPP__
#define __MOB_HPP__

#include "entity.hpp"

class mobBase : public entity {
    protected:
        int ev;
        int str;
        int hp;
        char img;

        int xPos;
        int yPos;
    public:
        mobBase(int ev, int str, int hp, char img) : ev(ev), str(str), hp(hp), img(img) {};

        // Pure virtual mob functions
};

class eldritchBitch : public mobBase {
    public:
        eldritchBitch() : mobBase(5, 5, 5, 'o') {};
};

#endif