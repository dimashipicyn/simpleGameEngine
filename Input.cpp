//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Headers.hpp"
#include "Input.hpp"
#include "MoveForwardCommand.hpp"

Input::Input() {
    moveForward_ = new MoveForwardCommand();
}

Input::~Input() {
    delete moveForward_;
}

Command *Input::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) return moveForward_;
    return nullptr;
}
