#include "scene.hpp"

#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

MenuBattle::MenuBattle() {
}

void MenuBattle::render(Game& game) {
    Render::drawRect(UI::UIMenuField["rect"], WHITE);
    Render::drawText("Paused", UI::UIMenuField["text_paused"]);
    Render::drawRect(UI::UIMenuField["button_resume"], YELLOW);
    Render::drawText("Resume", UI::UIMenuField["text_resume"]);
    Render::drawRect(UI::UIMenuField["button_exit"], PINK);
    Render::drawText("Exit to Title", UI::UIMenuField["text_exit"]);
    Render::drawRect(UI::UIMenuField["button_quit"], YELLOW);
    Render::drawText("Quit Game", UI::UIMenuField["text_quit"]);
}

void MenuBattle::mouseUp(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_resume"])) {
        game.menu = false;
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_exit"])) {
        game.menu = false;
        game.changeSceneTo(TITLE);
    } else if (Util::pointInsideRectUI(pos, UI::UIMenuField["button_quit"])) {
        game.running = false;
    }
}
