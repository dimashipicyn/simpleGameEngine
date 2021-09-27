//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_GAMEACTOR_HPP
#define ENGINE_GAMEACTOR_HPP
#include "Headers.hpp"


class GameActor {
public:
    GameActor() :
    moveForward_(false),
    moveBackward_(false),
    moveLeft_(false),
    moveRight_(false)
    {

    }
    void moveForward() {
        moveForward_ = true;
    }

private:
    sf::Vector2f position_;
    bool            moveForward_;
    bool            moveBackward_;
    bool            moveLeft_;
    bool            moveRight_;
};


#endif //ENGINE_GAMEACTOR_HPP
