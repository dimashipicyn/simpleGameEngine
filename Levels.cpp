//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Levels.hpp"

static std::string levelFileName[] = {
        "levels/level_1.txt",
        ""
};

Levels::Levels() :
levels_()
{
    loadLevels();
}

Levels::~Levels() {

}

void Levels::loadLevels() {
    Level           level;
    std::ifstream   f;

    for (int i = 0; !levelFileName[i].empty(); ++i) {
        f.open(levelFileName[i]);
        if (!f.is_open()) {
            std::cout << "Can't open " << levelFileName[i] << " " << strerror(errno) << std::endl;
            continue;
        }
        std::string line;
        std::getline(f, line);
        while (!line.empty()) {
            level.map.push_back(line);
            line.clear();
            std::getline(f, line);
        }
        levels_.push_back(level);
        f.close();
    }
}

const Levels::Level &Levels::get_level() {
    return levels_[0];
}
