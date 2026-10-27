#include "asset.hpp"

std::unordered_map<std::string, Texture2D> Asset::texture;

void Asset::assetLoad() {
    texture.emplace("button_menu", LoadTexture("asset/button_menu.png"));
    texture.emplace("entity", LoadTexture("asset/entity.png"));
    texture.emplace("arrow", LoadTexture("asset/arrow.png"));
}

void Asset::assetDispose() {
    for (auto& pair : texture) {
        UnloadTexture(pair.second);
    }

    texture.clear();
}
