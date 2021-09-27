//
// Created by Дима Щипицын on 27/09/2021.
//

#include "RotateLeftCommand.hpp"
#include "GameActor.hpp"

void RotateLeftCommand::execute(GameActor &actor) {
    actor.rotateLeft();
}
