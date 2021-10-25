//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_GAME_HPP
#define ENGINE_GAME_HPP
#include "Headers.hpp"
#include "Raycaster.hpp"
#include "GameObject.hpp"

class Game {
public:
    Game();
    Game(const std::string &title, int width, int height);
    ~Game();
    void run(World &world);

    const sf::RenderWindow &getWindow() const;

private:
    void    processEvents(sf::Event &event);
    void    update(World &world);
    void    render(World &world);

private:
    sf::RenderWindow    mWindow;
};


#endif //ENGINE_GAME_HPP
