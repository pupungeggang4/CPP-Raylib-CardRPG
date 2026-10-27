#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Scene;
class SceneTitle;
class Field;

class Game {
    public:
        // System var
        bool running;
        int width, height, logicWidth = 800, logicHeight = 600;
        float scale = 0;

        // Game system var
        std::unordered_map<int, shared_ptr<Scene>> scenes;
        shared_ptr<Scene> scene;
        int state = NORMAL;
        bool menu = false;

        // Game var
        shared_ptr<Field> field;

        Game();
        void init();
        void loop();
        void handleInput();
        void changeSceneTo(int);
};

extern Game game;

#endif
