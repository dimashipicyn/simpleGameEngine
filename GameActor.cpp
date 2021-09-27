//
// Created by Дима Щипицын on 27/09/2021.
//

#include "GameActor.hpp"

GameActor::GameActor():
position_(0, 0),
angle_(0),
step_(0.03),
moveForward_(false),
moveBackward_(false),
moveLeft_(false),
moveRight_(false),
rotateLeft_(false),
rotateRight_(false)
{

}

void GameActor::moveForward() {
    moveForward_ = true;
}

void GameActor::moveBackward() {
    moveBackward_ = true;
}

void GameActor::moveLeft() {
    moveLeft_ = true;
}

void GameActor::moveRight() {
    moveRight_ = true;
}

void GameActor::rotateLeft() {
    rotateLeft_ = true;
}

void GameActor::rotateRight() {
    rotateRight_ = true;
}

void GameActor::update() {
    if (moveForward_) {
        setPosition(sf::Vector2f(position().x + step_, position().y));
        moveForward_ = false;
    }
    if (rotateLeft_) {
        setAngle(angle() - step_);
        rotateLeft_ = false;
    }
}

void GameActor::setPosition(sf::Vector2f pos) {
    position_.x = pos.x;
    position_.y = pos.y;
}

sf::Vector2f GameActor::position() const {
    return position_;
}

void GameActor::setAngle(double a) {
    angle_ = a;
}

double GameActor::angle() const {
    return angle_;
}
