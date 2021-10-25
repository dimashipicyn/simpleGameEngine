//
// Created by Дима Щипицын on 05/10/2021.
//

#ifndef ENGINE_WORLD_HPP
#define ENGINE_WORLD_HPP
#include "Headers.hpp"
#include "Raycaster.hpp"
#include "GameObject.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerGraphicsComponent.hpp"

class World {
public:
    World();
    ~World() {}
    void    loadLevel();
    void    update();
    void    render(sf::RenderWindow &window);
    void    drawWall(sf::RenderWindow &window);

    std::vector<std::string>    map;
    std::vector<GameObject>     gameObjects;
    std::vector<sf::Sprite>     walls;
    GameObject                  player;
    sf::Vector2i                sizeWall;
private:
    sf::Texture                 mGameObjectTexture;
    sf::Texture                 mWallTexture;
    Raycaster                   mRaycaster;
};


#endif //ENGINE_WORLD_HPP
