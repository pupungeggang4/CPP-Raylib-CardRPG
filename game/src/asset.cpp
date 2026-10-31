#include "asset.hpp"

std::unordered_map<std::string, Texture2D> Asset::texture;

void Asset::assetLoad() {
    texture.emplace("button_menu", LoadTexture("asset/image/button_menu.png"));
    texture.emplace("entity", LoadTexture("asset/image/entity.png"));
    texture.emplace("arrow", LoadTexture("asset/image/arrow.png"));
    texture.emplace("player", LoadTexture("asset/image/player.png"));
}

void Asset::assetDispose() {
    for (auto& pair : texture) {
        UnloadTexture(pair.second);
    }

    texture.clear();
}
