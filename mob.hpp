#ifndef __MOB_HPP__
#define __MOB_HPP__

#include "entity.hpp"
#include <string.h>

class mobBase : public entity {
    protected:
        int ev;
        int str;
        int hp;
        const char* alert;
        const char* description;
    public:
        mobBase(int ev, int str, int hp, const char* alert, const char *description, char img) : ev(ev), str(str), hp(hp), alert(alert), description(description), entity(img) {};

        virtual void event(WINDOW* win) = 0;
};

class cultist : public mobBase {
    public:
        const char* alertMsg = "You have encountered a cultist!";
        const char* descriptionMsg = "Worshippers of the Great Old Ones who have self-mutilated for dark power, corroding their sanity and making them dangerous and unpredictable.";
        cultist() : mobBase(5, 5, 5, alertMsg, descriptionMsg, '$') {};

        virtual void event(WINDOW* win) {
            int row;
            int col;
            getmaxyx(win, row, col);

            mvprintw(8, strlen(alertMsg), alertMsg);
            mvprintw(10, strlen(descriptionMsg), descriptionMsg);
        }
};

#endif