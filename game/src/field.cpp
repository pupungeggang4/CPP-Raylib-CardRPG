#include "field.hpp"

#include "asset.hpp"
#include "game.hpp"

Field::Field() {
    camera.x = 0; camera.y = 0; camera.width = 800; camera.height = 600;
    for (int i = 0; i < 3; i++) {
        FieldEntity temp;
        temp.type = i + 1;
        temp.pos.x = i;
        temp.pos.y = i;
        entityList.push_back(temp);
    }
}

void Field::render(Game& game) {
    for (auto& value: entityList) {
        Rectangle source = {0, 0, 20, 20};
        if (value.type == PORTAL) source.x = 0;
        else if (value.type == SAVE) source.x = 20;
        else if (value.type == ENEMY) source.x = 40;
        Rectangle dest = {(float)value.pos.x * 40, (float)value.pos.y * 40, 40, 40};
        Vector2 origin = {0, 0};
        DrawTexturePro(Asset::texture["entity"], source, dest, origin, 0, WHITE);
    }
}
