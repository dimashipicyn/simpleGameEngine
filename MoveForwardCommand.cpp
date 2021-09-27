//
// Created by Дима Щипицын on 27/09/2021.
//

#include "MoveForwardCommand.hpp"
#include "GameActor.hpp"

void MoveForwardCommand::execute(GameActor &actor) {
    actor.moveForward();
}
