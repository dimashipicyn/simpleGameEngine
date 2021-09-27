//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_ROTATELEFTCOMMAND_HPP
#define ENGINE_ROTATELEFTCOMMAND_HPP
#include "ICommand.hpp"

class GameActor;

class RotateLeftCommand : public Command {
public:
    virtual void execute(GameActor &actor);
};


#endif //ENGINE_ROTATELEFTCOMMAND_HPP
