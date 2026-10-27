#include "scene.hpp"

#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneField::SceneField() {
    menuField = make_shared<MenuField>();
}

void SceneField::ready(Game& game) {
}

void SceneField::update(Game& game) {
}

void SceneField::render(Game& game) {
    Render::drawRect(UI::UIField["button_menu"], BLUE);

    if (game.menu) {
        menuField->render(game);
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

