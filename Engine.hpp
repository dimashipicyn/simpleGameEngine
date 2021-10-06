//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP
#include "Headers.hpp"
#include "Levels.hpp"
#include "Raycaster.hpp"
#include "GameObject.hpp"

class Engine {
public:
    Engine();
    Engine(const std::string &title, int width, int height);
    ~Engine();
    void gameLoop(World &world);
    //void input(std::vector<GameObject> &entities);
    void update(std::vector<GameObject> &gameObjects);
    void drawWall(World &world);
private:
    sf::RenderWindow    *window_;
    Raycaster           raycaster_;
};


#endif //ENGINE_ENGINE_HPP
