#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class MenuField;
class MenuBattle;

class Scene {
    public:
        int selectedTitle = 0;
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void keyDown(Game&);
        virtual void mouseUp(Game&, Vector2);
};

class SceneTitle : public Scene {
    public:
        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneField : public Scene {
    public:
        shared_ptr<MenuField> menuField;

        SceneField();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneBattle : public Scene {
    public:
        shared_ptr<MenuBattle> menuBattle;

        SceneBattle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class MenuField : public Scene {
    public:
        int selected = 0;

        MenuField();
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class MenuBattle : public Scene {
    public:
        int selected = 0;

        MenuBattle();
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&, Vector2) override;
};
#endif
