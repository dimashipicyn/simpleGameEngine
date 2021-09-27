//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_ICOMMAND_HPP
#define ENGINE_ICOMMAND_HPP

class GameActor;

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(GameActor &actor) = 0;
};

#endif //ENGINE_ICOMMAND_HPP
