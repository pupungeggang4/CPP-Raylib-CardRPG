#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Scene;
class SceneTitle;
class Game {
    public:
        bool running;
        int width, height, logicWidth = 800, logicHeight = 600;
        float scale = 0;

        std::unordered_map<int, shared_ptr<Scene>> scenes;
        shared_ptr<Scene> scene;
        int state = NORMAL;
        bool menu = false;

        Game();
        void init();
        void loop();
        void handleInput();
        void changeSceneTo(int);
};

extern Game game;

#endif
