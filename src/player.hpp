#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "entity.hpp"

class player : public entity {
    private:
        int ev;
        int str;
        int sanity;
    public:
        player();
};

#endif
