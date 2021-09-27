//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_MOVEFORWARDCOMMAND_HPP
#define ENGINE_MOVEFORWARDCOMMAND_HPP
#include "ICommand.hpp"

class MoveForwardCommand : public Command {
public:
    virtual void execute(GameActor &actor) {
        actor.moveForward();
    }
};


#endif //ENGINE_FORWARDMOVECOMMAND_HPP
