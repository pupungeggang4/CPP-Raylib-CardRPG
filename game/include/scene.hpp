#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
};

class SceneTitle : public Scene {
    public:
        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
};

#endif
