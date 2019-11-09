#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

class player : public entity {
    private:
        int ev;
        int str;
        int sanity;
    public:
        player() : ev(10), str(10), sanity(10) {};
};

#endif