//
// Created by Дима Щипицын on 28/09/2021.
//

#ifndef ENGINE_PLAYERINPUTCOMPONENT_HPP
#define ENGINE_PLAYERINPUTCOMPONENT_HPP
#include "InputComponent.hpp"
#include "Headers.hpp"

class PlayerInputComponent : public InputComponent {
public:
    PlayerInputComponent();
    ~PlayerInputComponent();
    void update(GameObject &gameObject) override;

private:
    int acceleration_;
};


#endif //ENGINE_PLAYERINPUTCOMPONENT_HPP
