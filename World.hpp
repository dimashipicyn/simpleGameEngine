//
// Created by Дима Щипицын on 05/10/2021.
//

#ifndef ENGINE_WORLD_HPP
#define ENGINE_WORLD_HPP
#include "Headers.hpp"
#include "GameObject.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerGraphicsComponent.hpp"

class World {
public:
    World() : player(new PlayerInputComponent(), 0, new PlayerGraphicsComponent()) {

    }
    ~World() {}
    std::vector<std::string>    map;
    std::vector<GameObject>     gameObjects;
    std::vector<sf::Sprite>     walls;
    GameObject                  player;
    sf::Vector2i                sizeWall;
    void    loadLevel();
private:
    sf::Texture                 gameObjectTexture_;
    sf::Texture                 wallTexture_;
};


#endif //ENGINE_WORLD_HPP
