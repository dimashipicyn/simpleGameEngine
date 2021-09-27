//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_INPUT_HPP
#define ENGINE_INPUT_HPP
#include "ICommand.hpp"

class Input {
public:
    Input();
    ~Input();
    Command* handleInput();

private:
    Command *moveForward_;
    Command *moveBackward_;
    Command *moveLeft_;
    Command *moveRight_;
    Command *rotateLeft_;
    Command *rotateRight_;
};


#endif //ENGINE_INPUT_HPP
