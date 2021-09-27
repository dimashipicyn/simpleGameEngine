//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP
#include "Headers.hpp"
#include "Input.hpp"
#include "ICommand.hpp"
#include "GameActor.hpp"

class Engine {
public:
    Engine() : input_() {
        window_ = new sf::RenderWindow(sf::VideoMode(800, 600),"Default");
    }
    Engine(const std::string &title, int width, int height) {
        window_ = new sf::RenderWindow(sf::VideoMode(width, height),title);
    }
    ~Engine() {
        delete window_;
    }
    void gameLoop(GameActor &player) {
        sf::Event event;
        while (window_->isOpen())
        {
            while (window_->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window_->close();
            }
            window_->clear();

            input(player);
            update();
            render();


            window_->display();
        }
    }
    void input(GameActor &gameActor) {
        Command * command = input_.handleInput();
        if (command) {
            command->execute(gameActor);
        }
    }
    void update() {

    }
    void render() {

    }
private:
    sf::RenderWindow    *window_;
    Input               input_;
};


#endif //ENGINE_ENGINE_HPP
