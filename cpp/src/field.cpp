#include "field.hpp"

#include "render.hpp"
#include "asset.hpp"
#include "game.hpp"

Field::Field() {
    camera.x = 0; camera.y = 0; camera.width = 800; camera.height = 600;
}

void Field::update(Game& game) {
    // Move Player
    if (!player.moving) {
        for (int i = 0; i < 4; i++) {
            if (game.keyPressed[i]) {
                player.moving = true;
                player.movedDistance = 0;
                player.facing = i;
                player.movingDirection = i;
                player.cellPos.x += directionCell[i][0];
                player.cellPos.y += directionCell[i][1];
                break;
            }
        }
    } else {
        player.pos.x += directionCell[player.movingDirection][0] * player.speed * game.dt;
        player.pos.y += directionCell[player.movingDirection][1] * player.speed * game.dt;
        player.movedDistance += player.speed * game.dt;
        if (player.movedDistance > 40) {
            player.pos.x = player.cellPos.x * 40;
            player.pos.y = player.cellPos.y * 40;
            player.moving = false;
            for (int i = 0; i < entityList.size(); i++) {
                FieldEntity entity = entityList[i];
                if (entity.type == ENEMY) {
                    if (entity.cellPos.x == player.cellPos.x && entity.cellPos.y == player.cellPos.y) {
                        entityList.erase(entityList.begin() + i);
                        game.changeSceneTo(BATTLE);
                        break;
                    }
                }
            }
        }
    }
}

void Field::render(Game& game) {
    // Adjusting camera
    camera.x = player.pos.x;
    camera.y = player.pos.y;

    // Rendering entities
    for (auto& value: entityList) {
        Rectangle source = {0, 0, 20, 20};
        if (value.type == PORTAL) source.x = 0;
        else if (value.type == SAVE) source.x = 20;
        else if (value.type == ENEMY) source.x = 40;
        Rectangle dest = {
            (float)value.cellPos.x * 40 - 20.0f - camera.x + camera.width / 2.0f,
            (float)value.cellPos.y * 40 - 20.0f - camera.y + camera.height / 2.0f,
            40, 40};
        Vector2 origin = {0, 0};
        DrawTexturePro(Asset::texture["entity"], source, dest, origin, 0, WHITE);
    }

    // Rendering player
    player.frameTime += game.dt;
    int frame = 0;
    if (player.moving) frame += 8;
    frame += player.facing * 2 + (int)(player.frameTime / 0.4f) % 2;
    int col = frame % 4;
    int row = (frame - col) / 4;
    Rectangle rect = {float(col) * 20, float(row) * 20, 20, 20};
    Rectangle dest = {
        player.pos.x - 20.0f - camera.x + camera.width / 2.0f,
        player.pos.y - 20.0f - camera.y + camera.height / 2.0f,
        40, 40};
    Vector2 origin = {0, 0};
    DrawTexturePro(Asset::texture["player"], rect, dest, origin, 0, WHITE);
}

void Field::loadField(int place) {
    entityList.clear();

    for (int i = 0; i < 100; i++) {
        if (FieldData::dataCell[place][i][0] == PORTAL) {
            FieldEntity entity;
            entity.type = PORTAL;
            entity.cellPos.x = FieldData::dataCell[place][i][1];
            entity.cellPos.y = FieldData::dataCell[place][i][2];
            entity.destination = FieldData::dataCell[place][i][3];
            entity.desPos.x = FieldData::dataCell[place][i][4];
            entity.desPos.y = FieldData::dataCell[place][i][5];
            entityList.push_back(entity);
        } else if (FieldData::dataCell[place][i][0] == ENEMY) {
            FieldEntity entity;
            entity.type = ENEMY;
            entity.cellPos.x = FieldData::dataCell[place][i][1];
            entity.cellPos.y = FieldData::dataCell[place][i][2];
            entityList.push_back(entity);
        } else if (FieldData::dataCell[place][i][0] == SAVE) {
            FieldEntity entity;
            entity.type = SAVE;
            entity.cellPos.x = FieldData::dataCell[place][i][1];
            entity.cellPos.y = FieldData::dataCell[place][i][2];
            entityList.push_back(entity);
        }
    }
}