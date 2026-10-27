#ifndef FIELD_HPP
#define FIELD_HPP

#include "includes.hpp"
#include "shape.hpp"

class Game;

class FieldPlayer {
    public:
        Vector2 pos;
        Vector2i cellPos;
        Vector2i destination;
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
        std::string place;
        std::vector<int> enemyPool;
        std::vector<Recti> wall;
        
        Rectangle camera;
        FieldPlayer player;
        std::vector<FieldEntity> entityList;

        Field();
        void render(Game&);
};

#endif
