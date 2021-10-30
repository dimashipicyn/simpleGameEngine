//
// Created by Дима Щипицын on 29/10/2021.
//

#ifndef ENGINE_TEXTURES_H
#define ENGINE_TEXTURES_H
#include "ResourceHolder.h"

namespace Textures {
    enum ID {
        WEAPON_KNOCK,
        WEAPON_PISTOL
    };
    extern ResourceHolder<sf::Texture, Textures::ID> mTextures;
}

#endif //ENGINE_TEXTURES_H
