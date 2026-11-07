#include "scene.hpp"

#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "render.hpp"

#include "game.hpp"

WindowInventory::WindowInventory() {

}

void WindowInventory::render(Game& game) {
    Render::drawRect(UI::UIInventory["rect"], YELLOW);
    Render::drawRect(UI::UIInventory["button_close"], RED);
}

void WindowInventory::mouseUp(Game& game, Vector2 pos) {

}

void WindowInventory::keyDown(Game& game) {

}
