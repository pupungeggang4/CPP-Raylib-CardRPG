#ifndef FIELD_HPP
#define FIELD_HPP

#include "includes.hpp"
#include "shape.hpp"

class Game;

class FieldPlayer {
    public:
        Vector2 pos = {0, 0};
        Vector2i cellPos = {0, 0};
        Vector2i destination = {0, 0};
        int facing = DOWN;

        bool moving = false;
        float movedDistance = 0;
        int movingDirection = DOWN;
};

class FieldEntity {
    public:
        int type = 0;
        Vector2i pos;
};

class Field {
    public:
        std::array<std::array<float, 2>, 4> directionCell = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        std::string place;
        std::vector<int> enemyPool;
        std::vector<Recti> wall;
        
        Rectangle camera;
        FieldPlayer player;
        std::vector<FieldEntity> entityList;

        Field();
        void update(Game&);
        void render(Game&);
};

#endif
