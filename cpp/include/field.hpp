#ifndef FIELD_HPP
#define FIELD_HPP

#include "includes.hpp"
#include "shape.hpp"

enum FIeldPlace {HOME_TOWN, PLAIN_1, PLAIN_2};

class Game;

class FieldPlayer {
    public:
        Vector2 pos = {0, 0};
        Vector2i cellPos = {0, 0};
        Vector2i destination = {0, 0};
        float speed = 320;

        float frameTime = 0;

        int facing = DOWN;
        bool moving = false;
        float movedDistance = 0;
        int movingDirection = DOWN;
};

class FieldEntity {
    public:
        int type = 0;
        Vector2 pos;
        Vector2i cellPos;
        int destination;
        Vector2i desPos;
};

class Field {
    public:
        std::array<std::array<float, 2>, 4> directionCell = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        int place;
        std::vector<int> enemyPool;
        std::vector<Recti> wall;
        
        Rectangle camera = {0.0f, 0.0f, 800.0f, 600.0f};
        FieldPlayer player;
        std::vector<FieldEntity> entityList;

        Field();
        void loadField(int);
        void update(Game&);
        void render(Game&);
};

class FieldData {
    public:
        static std::unordered_map<int, std::string> dataPath;
        static std::array<std::array<std::array<int, 6>, 100>, 100> dataCell;
        static std::array<std::array<std::array<int, 6>, 100>, 100> dataWall;
        static void loadFieldData();
};

#endif
