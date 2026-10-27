#ifndef FIELD_HPP
#define FIELD_HPP

#include "includes.hpp"
#include "shape.hpp"

class Game;

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
        FieldEntity player;
        std::vector<FieldEntity> entityList;

        Field();
        void render(Game&);
};

#endif
