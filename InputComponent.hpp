//
// Created by Дима Щипицын on 28/09/2021.
//

#ifndef ENGINE_INPUTCOMPONENT_HPP
#define ENGINE_INPUTCOMPONENT_HPP

class GameObject;

class InputComponent {
public:
    virtual ~InputComponent() {}
    virtual void update(GameObject &gameObject) = 0;
};

#endif //ENGINE_INPUTCOMPONENT_HPP
