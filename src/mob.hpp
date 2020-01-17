#ifndef __MOB_HPP__
#define __MOB_HPP__

#include "entity.hpp"

class mobBase : public entity {
    protected:
        int ev;
        int str;
        int hp;
        const char* alert;
        const char* description;
    public:
        mobBase(int ev, int str, int hp, const char* alert, const char *description, char img); 

        virtual void event(WINDOW* win) = 0;
};

#endif
