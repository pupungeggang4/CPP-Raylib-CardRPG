#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Game {
    public:
        bool running;
        int width, height;
        Camera2D camera = {0};

        Game();
        void init();
        void loop();
};

extern Game game;

#endif
