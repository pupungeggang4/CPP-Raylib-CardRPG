#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

MenuBattle::MenuBattle() {
}

void MenuBattle::render(Game& game) {
    Render::drawRect(UI::UIMenuBattle["rect"], WHITE);
    Render::drawText("Paused", UI::UIMenuBattle["text_paused"]);
    Render::drawRect(UI::UIMenuBattle["button_resume"], YELLOW);
    Render::drawText("Resume", UI::UIMenuBattle["text_resume"]);
    Render::drawRect(UI::UIMenuBattle["button_surrender"], PINK);
    Render::drawText("Surrender", UI::UIMenuBattle["text_surrender"]);
    Render::drawRect(UI::UIMenuBattle["button_exit"], YELLOW);
    Render::drawText("Exit to Title", UI::UIMenuBattle["text_exit"]);
    Render::drawRect(UI::UIMenuBattle["button_quit"], PINK);
    Render::drawText("Quit Game", UI::UIMenuBattle["text_quit"]);

    std::array<float, 6> arrowPos = {
        UI::UIMenuBattle["arrow"][0], UI::UIMenuBattle["arrow"][1] + UI::UIMenuBattle["arrow"][3] * selected
    };

    Render::drawTexture(Asset::texture["arrow"], arrowPos);
}

void MenuBattle::keyDown(Game& game) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) selected = (selected + 1) % 4;
    else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) selected = (selected + 3) % 4;
    else if (IsKeyPressed(KEY_ENTER)) {
        if (selected == 0) game.menu = false;
        else if (selected == 1) {
            game.menu = false;
            game.changeSceneTo(FIELD);
        } else if (selected == 2) {
            game.menu = false;
            game.changeSceneTo(TITLE);
        } else if (selected == 3) game.running = false;
    }
}



void MenuBattle::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_resume"])) {
        game.menu = false;
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_surrender"])) {
        game.menu = false;
        game.changeSceneTo(FIELD);
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_exit"])) {
        game.menu = false;
        game.changeSceneTo(TITLE);
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_quit"])) {
        game.running = false;
    }
}
