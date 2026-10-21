#ifndef RENDER_HPP
#define RENDER_HPP

#include "includes.hpp"

class Render {
    public:
        static void drawRect(std::vector<float>, Color color = BLACK);
        static void drawText(std::string, std::vector<float>, int size = 20, Color color = BLACK);
};

#endif
