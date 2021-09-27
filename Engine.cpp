//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Engine.hpp"

Engine::Engine() : input_(), raycaster_(800) {
    window_ = new sf::RenderWindow(sf::VideoMode(800, 600),"Default");
    window_->setFramerateLimit(60);
}

Engine::~Engine() {
    delete window_;
}

Engine::Engine(const std::string &title, int width, int height) : input_(), raycaster_(width) {
    window_ = new sf::RenderWindow(sf::VideoMode(width, height),title);
    window_->setFramerateLimit(30);
}

void Engine::input(GameActor &gameActor) {
    Command * command = input_.handleInput();
    if (command) {
        command->execute(gameActor);
    }
}

void Engine::gameLoop(GameActor &player, Levels &levels) {
    sf::Event event;
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("textures/paper_2.jpg");
    sf::Vector2u s = texture.getSize();
    sprite.setTexture(texture);
    while (window_->isOpen())
    {
        while (window_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_->close();
        }
        window_->clear();
        raycaster_.raycasting(levels.get_level().map, player);
        input(player);
        update(player);
        render(sprite, s);

        //exit(0);
        window_->display();
    }
}

void Engine::update(GameActor &gameActor) {
    gameActor.update();
}

void Engine::render(sf::Sprite &sprite, sf::Vector2u s) {
    int winSizeY = static_cast<int>(window_->getSize().y);
    for (int i = 0; i < raycaster_.getNRays(); ++i) {
        Raycaster::Ray ray = raycaster_.getRay(i);
        int height = s.y / ray.len;
        float scale = 1.0 / ray.len;
        float hit = ray.side ? fabs((int)ray.pos.x - ray.pos.x) : fabs((int)ray.pos.y - ray.pos.y);
        sprite.setTextureRect(sf::IntRect(hit * s.x, 0, 1, s.y));
        sprite.setPosition(sf::Vector2f(i, (winSizeY - height) / 2));
        sprite.setScale(sf::Vector2f(1, scale));
        window_->draw(sprite);
    }
}
