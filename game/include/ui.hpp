#ifndef UI_HPP
#define UI_HPP

#include "includes.hpp"

class UI {
    public:
        static std::unordered_map<std::string, std::vector<float>> UITitle;
        static std::unordered_map<std::string, std::vector<float>> UIField, UIMenuField;
        static std::unordered_map<std::string, std::vector<float>> UIBattle, UIMenuBattle;
};

#endif
