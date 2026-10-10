#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Game {
    public:
        bool running;

        Game();
        void init();
        void loop();
};

extern Game game;

#endif
