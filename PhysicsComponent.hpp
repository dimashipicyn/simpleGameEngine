//
// Created by Дима Щипицын on 28/09/2021.
//

#ifndef ENGINE_PHYSICSCOMPONENT_HPP
#define ENGINE_PHYSICSCOMPONENT_HPP

class GameObject;

class PhysicsComponent {
public:
    virtual ~PhysicsComponent();
    virtual void update(GameObject& gameObject) = 0;
};

#endif //ENGINE_PHYSICSCOMPONENT_HPP
