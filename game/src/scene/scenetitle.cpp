#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

SceneTitle::SceneTitle() {
}

void SceneTitle::ready(Game& game) {
    selectedTitle = 0;
}

void SceneTitle::update(Game& game) {
}

void SceneTitle::render(Game& game) {
    Render::drawText("PlanterGuy CardRPG", UI::UITitle["text_title"]);
    Render::drawRect(UI::UITitle["button_start"], YELLOW);
    Render::drawText("Start Game", UI::UITitle["text_start"]);
    Render::drawRect(UI::UITitle["button_erase"], PINK);
    Render::drawText("Erase Data", UI::UITitle["text_erase"]);
    Render::drawRect(UI::UITitle["button_quit"], YELLOW);
    Render::drawText("Quit Game", UI::UITitle["text_quit"]);

    std::array<float, 6> rect = {
        UI::UITitle["arrow"][0], UI::UITitle["arrow"][1] + UI::UITitle["arrow"][3] * selectedTitle
    };
    Render::drawTexture(Asset::texture["arrow"], rect);
}

void SceneTitle::keyDown(Game& game) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) selectedTitle = (selectedTitle + 1) % 3;
    else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) selectedTitle = (selectedTitle + 2) % 3;
    else if (IsKeyPressed(KEY_ENTER)) {
        if (selectedTitle == 0) game.changeSceneTo(FIELD);
        else if (selectedTitle == 2) game.running = false;
   }
}

void SceneTitle::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UITitle["button_start"])) game.changeSceneTo(FIELD);
    else if (Util::pointInsideRectUI(pos, UI::UITitle["button_quit"])) game.running = false;
}

