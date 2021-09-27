//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_GAMEACTOR_HPP
#define ENGINE_GAMEACTOR_HPP
#include "Headers.hpp"


class GameActor {
public:
    GameActor();
    void            setPosition(sf::Vector2f pos);
    sf::Vector2f    position() const;
    void            setAngle(double a);
    double          angle() const;
    void            moveForward();
    void            moveBackward();
    void            moveLeft();
    void            moveRight();
    void            rotateLeft();
    void            rotateRight();
    void            update();

private:
    sf::Vector2f    position_;
    double          angle_;
    float           step_;
    bool            moveForward_;
    bool            moveBackward_;
    bool            moveLeft_;
    bool            moveRight_;
    bool            rotateLeft_;
    bool            rotateRight_;
};


#endif //ENGINE_GAMEACTOR_HPP
