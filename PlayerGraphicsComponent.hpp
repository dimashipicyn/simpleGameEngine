//
// Created by Дима Щипицын on 02/10/2021.
//

#ifndef ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#define ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#include "GraphicsComponent.hpp"
#include "Headers.hpp"
#include "Textures.h"

class PlayerGraphicsComponent : public GraphicsComponent {
public:
    PlayerGraphicsComponent() : num(0) {
        sf::Texture &texture = Textures::mTextures.get(Textures::WEAPON_PISTOL);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        int sizeX = texture.getSize().x / 64;
        int sizeY = texture.getSize().y / 64;
        for (int i = 0; i < sizeY; ++i) {
            int offsetY = i * 65;
            for (int j = 0; j < sizeX; ++j) {
                int offsetX = j * 65;
                sprite.setTextureRect(sf::IntRect(offsetX, offsetY, 64, 64));
                sprite.setPosition(270, 350);
                sprite.setScale(4, 4);
                sprites_.push_back(sprite);
            }
        }
    }

    ~PlayerGraphicsComponent() override {

    }

    void update(GameObject &gameObject) override {
        num += 0.1;
            num = 5;
    }
    void render(sf::RenderWindow &window) override {
        window.draw(sprites_[static_cast<int>(num)]);
    }

private:
    std::vector<sf::Sprite> sprites_;
    float                   num;
};


#endif //ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
