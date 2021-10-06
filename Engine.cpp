//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Engine.hpp"
//#include "GameObject.hpp"
#include "World.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerPhysicsComponent.hpp"
#include "PlayerGraphicsComponent.hpp"

Engine::Engine() : raycaster_(800) {
    window_ = new sf::RenderWindow(sf::VideoMode(800, 600),"Default");
    window_->setFramerateLimit(30);
}

Engine::~Engine() {
    delete window_;
}

Engine::Engine(const std::string &title, int width, int height) : raycaster_(width) {
    window_ = new sf::RenderWindow(sf::VideoMode(width, height),title);
    window_->setFramerateLimit(30);
}

float scalarMul(sf::Vector2f one, sf::Vector2f two)
{
    return one.x * two.x + one.y * two.y;
}

void Engine::drawWall(World &world) {
    sf::Sprite      wall;
    sf::IntRect     wallRect;
    sf::Vector2f    posPlr   = world.player.getPosition();
    int             winSizeY = static_cast<int>(window_->getSize().y);
    for (int i = 0; i < raycaster_.getNRays(); ++i) {
        Raycaster::Ray ray = raycaster_.getRay(i);
        int height = winSizeY / ray.len;
        float scale = winSizeY / 64 / ray.len;
        float offset = ray.side == 0 ? posPlr.y + ray.len * ray.dir.y : posPlr.x + ray.len * ray.dir.x;
        offset -= floor(offset);
        wall = world.walls[ray.wallnum - 'A'];
        wallRect = wall.getTextureRect();
        wallRect.left = wallRect.left + 64 * offset;
        wall.setTextureRect(wallRect);
        float y = roundf((winSizeY - height) / 2.0);
        wall.setPosition(sf::Vector2f(i, y));
        wall.setScale(sf::Vector2f(1, scale));
        if (ray.side)
            wall.setColor(sf::Color(255, 255, 255, 200));
        else
            wall.setColor(sf::Color(255, 255, 255, 255));
        window_->draw(wall);
    }
}

void Engine::gameLoop(World &world) {
    sf::Event event;

    while (window_->isOpen())
    {
        while (window_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_->close();
        }
        window_->clear();

        raycaster_.raycasting(world.map, world.player);
        drawWall(world);
        world.player.update();
        //update(world.gameObjects);

        world.player.render(window_);
        window_->display();
    }
}


void Engine::update(std::vector<GameObject> &gameObjects) {
    for (int i = 0; i < gameObjects.size(); ++i) {
        gameObjects[i].update();
    }
}

