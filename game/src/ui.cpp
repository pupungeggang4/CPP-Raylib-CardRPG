#include "ui.hpp"

std::unordered_map<std::string, std::vector<float>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 80, 480, 80}},
    {"text_start", {180, 100}},
    {"button_erase", {160, 160, 480, 80}},
    {"text_erase", {180, 180.0f}},
    {"button_quit", {160, 240, 480, 80}},
    {"text_quit", {180, 260}},
};

std::unordered_map<std::string, std::vector<float>> UI::UIField = {
    {"button_menu", {740, 20, 40, 40}},
};

std::unordered_map<std::string, std::vector<float>> UI::UIBattle = {
};

std::unordered_map<std::string, std::vector<float>> UI::UIMenuField = {
    {"rect", {160, 140, 480, 320}},
    {"text_paused", {180, 160}},
    {"button_resume", {160, 220, 480, 80}},
    {"text_resume", {180, 240}},
    {"button_exit", {160, 300, 480, 80}},
    {"text_exit", {180, 320}},
    {"button_quit", {160, 380, 480, 80}},
    {"text_quit", {180, 400}},
};

std::unordered_map<std::string, std::vector<float>> UI::UIMenuBattle = {
};
