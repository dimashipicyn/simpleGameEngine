//
// Created by Дима Щипицын on 02/10/2021.
//

#ifndef ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#define ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#include "GraphicsComponent.hpp"
#include "Headers.hpp"

class PlayerGraphicsComponent : public GraphicsComponent {
public:
    PlayerGraphicsComponent() : num(0) {
        texture_.loadFromFile("textures/soldat.png");
        sf::Sprite sprite;
        sprite.setTexture(texture_);
        int sizeX = texture_.getSize().x / 64;
        int sizeY = texture_.getSize().y / 64;
        for (int i = 0; i < sizeY; ++i) {
            int offsetY = i * 64;
            for (int j = 0; j < sizeX; ++j) {
                int offsetX = j * 64;
                sprite.setTextureRect(sf::IntRect(offsetX, offsetY, 64, 64));
                sprites_.push_back(sprite);
            }
        }
    }

    ~PlayerGraphicsComponent() override {

    }

    void update(GameObject &gameObject) override {
        num += 0.1;
        if (num >= 7)
            num = 0;
    }
    void render(sf::RenderWindow *window) override {
        window->draw(sprites_[static_cast<int>(num)]);
    }

private:
    sf::Texture             texture_;
    std::vector<sf::Sprite> sprites_;
    float                   num;
};


#endif //ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
