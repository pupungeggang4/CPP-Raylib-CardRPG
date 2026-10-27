#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class MenuField;
class MenuBattle;

class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void mouseUp(Game&, Vector2);
};

class SceneTitle : public Scene {
    public:
        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneField : public Scene {
    public:
        shared_ptr<MenuField> menuField;

        SceneField();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneBattle : public Scene {
    public:
        SceneBattle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class MenuField : public Scene {
    public:
        MenuField();
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class MenuBattle : public Scene {
    public:
        MenuBattle();
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};
#endif
