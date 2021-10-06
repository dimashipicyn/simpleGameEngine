//
// Created by Дима Щипицын on 28/09/2021.
//

#include "GameObject.hpp"
#include "InputComponent.hpp"
#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"

GameObject::GameObject(InputComponent *input, PhysicsComponent *physics, GraphicsComponent *graphics) :
input_(input), physics_(physics), graphics_(graphics)
{

}

GameObject::~GameObject() {

}

void GameObject::update() {
    input_->update(*this);
    //physics_->update(*this, world);
    graphics_->update(*this);
}

void GameObject::render(sf::RenderWindow *window) {
    graphics_->render(window);
}
