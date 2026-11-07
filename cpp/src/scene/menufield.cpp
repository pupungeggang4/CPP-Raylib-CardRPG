#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

MenuField::MenuField() {
}

void MenuField::render(Game& game) {
    Render::drawRect(UI::UIMenuField["rect"], WHITE);
    Render::drawText("Paused", UI::UIMenuField["text_paused"]);
    Render::drawRect(UI::UIMenuField["button_resume"], YELLOW);
    Render::drawText("Resume", UI::UIMenuField["text_resume"]);
    Render::drawRect(UI::UIMenuField["button_exit"], PINK);
    Render::drawText("Exit to Title", UI::UIMenuField["text_exit"]);
    Render::drawRect(UI::UIMenuField["button_quit"], YELLOW);
    Render::drawText("Quit Game", UI::UIMenuField["text_quit"]);

    std::array<float, 6> arrowPos = {
        UI::UIMenuField["arrow"][0], UI::UIMenuField["arrow"][1] + UI::UIMenuField["arrow"][3] * selected
    };

    Render::drawTexture(Asset::texture["arrow"], arrowPos);
}

void MenuField::keyDown(Game& game) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) selected = (selected + 1) % 3;
    else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) selected = (selected + 2) % 3;
    else if (IsKeyPressed(KEY_ENTER)) {
        if (selected == 0) game.menu = false;
        else if (selected == 1) {
            game.menu = false;
            game.changeSceneTo(TITLE);
        } else if (selected == 2) game.running = false;
    }
}

void MenuField::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_resume"])) {
        game.menu = false;
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_exit"])) {
        game.menu = false;
        game.changeSceneTo(TITLE);
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_quit"])) {
        game.running = false;
    }
}
