//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_LEVELS_HPP
#define ENGINE_LEVELS_HPP
#include "Headers.hpp"

class Levels {
private:
    struct Level {
        std::vector<std::string>    map;
        std::vector<sf::Sprite>     walls;
    };
    std::vector<Level>              levels_;
    void loadLevels();
public:
    Levels();
    ~Levels();
    const Level   &get_level();

};


#endif //ENGINE_LEVELS_HPP
