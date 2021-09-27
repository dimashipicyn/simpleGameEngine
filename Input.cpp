//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Headers.hpp"
#include "Input.hpp"
#include "MoveForwardCommand.hpp"
#include "RotateLeftCommand.hpp"

Input::Input() {
    moveForward_ = new MoveForwardCommand();
    rotateLeft_ = new RotateLeftCommand();
}

Input::~Input() {
    delete moveForward_;
    delete rotateLeft_;
}

Command *Input::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) return moveForward_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return rotateLeft_;
    return nullptr;
}
