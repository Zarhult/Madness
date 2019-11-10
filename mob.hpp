#ifndef __MOB_HPP__
#define __MOB_HPP__

#include "entity.hpp"
#include <string>

class mobBase : public entity {
    protected:
        int ev;
        int str;
        int hp;
        std::string description;
    public:
        mobBase(int ev, int str, int hp, std::string description, char img) : ev(ev), str(str), hp(hp), description(description), entity(img) {};

        virtual void event(WINDOW* win) = 0;
};

class cultist : public mobBase {
    public:
        std::string description = "Worshippers of the Dark One who have self-mutilated for dark power, which has corroded their sanity and made them dangerous and unpredictable.";
        cultist() : mobBase(5, 5, 5, description, '$') {};

        virtual void event(WINDOW* win) {

        }
};

#endif