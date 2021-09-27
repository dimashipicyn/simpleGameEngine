//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP
#include "Headers.hpp"
#include "Input.hpp"
#include "ICommand.hpp"
#include "GameActor.hpp"
#include "Levels.hpp"
#include "Raycaster.hpp"

class Engine {
public:
    Engine();
    Engine(const std::string &title, int width, int height);
    ~Engine();
    void gameLoop(GameActor &player, Levels &levels);
    void input(GameActor &gameActor);
    void update(GameActor &gameActor);
    void render(sf::Sprite &sprite, sf::Vector2u s);
private:
    sf::RenderWindow    *window_;
    Input               input_;
    Raycaster           raycaster_;
};


#endif //ENGINE_ENGINE_HPP
