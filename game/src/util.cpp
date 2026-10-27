#include "util.hpp"

bool Util::pointInsideRectUI(Vector2 pos, const std::array<float, 6>& rect) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}
