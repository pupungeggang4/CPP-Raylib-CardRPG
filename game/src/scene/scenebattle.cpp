#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneBattle::SceneBattle() {
    menuBattle = make_shared<MenuBattle>();
}

void SceneBattle::ready(Game& game) {
    game.menu = false;
}

void SceneBattle::update(Game& game) {
}

void SceneBattle::render(Game& game) {
    Render::drawTexture(Asset::texture["button_menu"], UI::UIBattle["button_menu"]);

    if (game.menu == true) {
        menuBattle->render(game);
    }
}

void SceneBattle::keyDown(Game& game) {
    if (game.menu == true) {
        menuBattle->keyDown(game);
        if (IsKeyPressed(KEY_ESCAPE)) game.menu = false;
    } else {
        if (IsKeyPressed(KEY_ESCAPE)) game.menu = true;
    }
}

void SceneBattle::mouseUp(Game& game, Vector2 pos) {
    if (game.menu == true) {
        menuBattle->mouseUp(game, pos);
        if (Util::pointInsideRectUI(pos, UI::UIBattle["button_menu"])) game.menu = false;
    } else {
        if (Util::pointInsideRectUI(pos, UI::UIBattle["button_menu"])) game.menu = true;
    }
}

