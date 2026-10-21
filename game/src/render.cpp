#include "render.hpp"

void Render::drawRect(std::vector<float> rect, Color color) {
    DrawRectangle(rect[0], rect[1], rect[2], rect[3], color);
}

void Render::drawText(std::string text, std::vector<float> pos, int size, Color color) {
    const char* cText = text.c_str();
    DrawText(cText, pos[0], pos[1], size, color);
}
