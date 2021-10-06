//
// Created by Дима Щипицын on 28/09/2021.
//
#include "Headers.hpp"
#include "PlayerInputComponent.hpp"
#include "GameObject.hpp"

PlayerInputComponent::PlayerInputComponent() : acceleration_(0.1) {

}

PlayerInputComponent::~PlayerInputComponent() {

}

sf::Vector2f rotate(sf::Vector2f point, float angle){
    sf::Vector2f rotated_point;
    rotated_point.x = point.x * cos(angle) - point.y * sin(angle);
    rotated_point.y = point.x * sin(angle) + point.y * cos(angle);
    return rotated_point;
}

void PlayerInputComponent::update(GameObject &gameObject) {
    float acc = 0.1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        gameObject.setPosition(gameObject.getPosition() + gameObject.getDir() * acc);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        gameObject.setPosition(gameObject.getPosition() - gameObject.getDir() * acc);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        gameObject.setDir(rotate(gameObject.getDir(), -0.1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        gameObject.setDir(rotate(gameObject.getDir(), 0.1));
    }
}
