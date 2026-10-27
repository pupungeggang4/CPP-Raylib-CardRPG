#ifndef UI_HPP
#define UI_HPP

#include "includes.hpp"

class UI {
    public:
        static std::unordered_map<std::string, std::array<float, 6>> UITitle;
        static std::unordered_map<std::string, std::array<float, 6>> UIField, UIMenuField;
        static std::unordered_map<std::string, std::array<float, 6>> UIBattle, UIMenuBattle;
};

#endif
