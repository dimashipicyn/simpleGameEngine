//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Game.hpp"
#include "World.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerPhysicsComponent.hpp"
#include "PlayerGraphicsComponent.hpp"

Game::Game() :
mWindow(sf::VideoMode(800, 600), "Default")
{
    //mWindow->setFramerateLimit(30);
    mWindow.setVerticalSyncEnabled(true);
}

Game::~Game() {
}

Game::Game(const std::string &title, int width, int height) :
mWindow(sf::VideoMode(width, height), title)
{
    //mWindow->setFramerateLimit(30);
}

void Game::run(World &world) {
    sf::Event   event;
    sf::Clock   clock;
    sf::Time    frameTime;

    frameTime = sf::seconds(1 / 60.0);
    while (mWindow.isOpen())
    {
        clock.restart();

        // classic game pattern
        processEvents(event);
        update(world);
        render(world);

        sf::Time elapsed = clock.getElapsedTime();
        //sf::sleep(frameTime - elapsed);
    }
}

void Game::processEvents(sf::Event &event) {
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::render(World &world) {
    mWindow.clear();
    world.render(mWindow);
    mWindow.display();
}

void Game::update(World &world) {
    world.update();
}

const sf::RenderWindow &Game::getWindow() const {
    return mWindow;
}

