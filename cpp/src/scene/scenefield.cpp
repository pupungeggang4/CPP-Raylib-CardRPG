#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "field.hpp"

#include "game.hpp"

SceneField::SceneField() {
    menuField = make_shared<MenuField>();
    windowInventory = make_shared<WindowInventory>();
}

void SceneField::ready(Game& game) {
    game.menu = false;
}

void SceneField::update(Game& game) {
    if (game.menu == false) {
        if (game.state == NORMAL) {
            game.field->update(game);
        }
    }
}

void SceneField::render(Game& game) {
    game.field->render(game);

    Render::drawText("WASD Move I Inventory E Interact", UI::UIField["text_key"]);
    Render::drawTexture(Asset::texture["button_menu"], UI::UIField["button_menu"]);

    if (game.state == INVENTORY) windowInventory->render(game);

    if (game.menu) {
        menuField->render(game);
    }
}

void SceneField::keyDown(Game& game) {
    if (game.menu) {
        menuField->keyDown(game);
        if (IsKeyPressed(KEY_ESCAPE)) {
            game.menu = false;
        }
    } else {
        if (IsKeyPressed(KEY_ESCAPE)) {
            game.menu = true;
        }

        if (game.state == NORMAL) {
            if (IsKeyPressed(KEY_I)) {
                game.state = INVENTORY;
            }
        } else if (game.state == INVENTORY) {
            if (IsKeyPressed(KEY_I)) {
                game.state = NORMAL;
            }
            windowInventory->keyDown(game);
        }
    }
}

void SceneField::mouseUp(Game& game, Vector2 pos) {
    if (game.menu) {
        menuField->mouseUp(game, pos);
        if (Util::pointInsideRectUI(pos, UI::UIField["button_menu"])) {
            game.menu = false;
        }
    } else {
        if (Util::pointInsideRectUI(pos, UI::UIField["button_menu"])) {
            game.menu = true;
        }
    }
}

