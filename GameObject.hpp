//
// Created by Дима Щипицын on 28/09/2021.
//

#ifndef ENGINE_GAMEOBJECT_HPP
#define ENGINE_GAMEOBJECT_HPP
#include "Headers.hpp"

class World;
class InputComponent;
class PhysicsComponent;
class GraphicsComponent;

class GameObject {
public:
    GameObject(InputComponent *input, PhysicsComponent *physics, GraphicsComponent *graphics);
    ~GameObject();
    void            setPosition(sf::Vector2f pos) {position_ = pos;};
    sf::Vector2f    getPosition() const {return position_;};
    void            setDir(sf::Vector2f dir) {dir_ = dir;};
    sf::Vector2f    getDir() const {return dir_;};
    void            update();
    void            render(sf::RenderWindow &window);

protected:
    sf::Vector2f        position_;
    sf::Vector2f        dir_;
public:
    const sf::CircleShape &getCollisionShape() const;

    void setCollisionShape(const sf::CircleShape &collisionShape);

protected:
    sf::CircleShape     collisionShape_;
    InputComponent      *input_;
    PhysicsComponent    *physics_;
    GraphicsComponent   *graphics_;
};

#endif //ENGINE_GAMEOBJECT_HPP
