//
// Created by Дима Щипицын on 02/10/2021.
//

#ifndef ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#include "PhysicsComponent.hpp"

class PlayerPhysicsComponent : public PhysicsComponent {
public:
    ~PlayerPhysicsComponent() override;

    void update(GameObject &gameObject) override;
};


#endif //ENGINE_PLAYERPHYSICSCOMPONENT_HPP
