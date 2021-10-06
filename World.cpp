//
// Created by Дима Щипицын on 05/10/2021.
//

#include "World.hpp"

void World::loadLevel() {
    std::string     line;
    std::ifstream   f;
    f.open("level_1.txt");
    if (!f.is_open()) {
        std::cout << "Can't open " << "level_1.txt" << " " << strerror(errno) << std::endl;
        return;
    }
    std::getline(f, line);
    while (!line.empty()) {
        map.push_back(line);
        line.clear();
        std::getline(f, line);
    }
    wallTexture_.loadFromFile("textures/walls.png");
    gameObjectTexture_.loadFromFile("textures/hitler1.BMP");
    sf::Sprite wall;
    wall.setTexture(wallTexture_);
    int sizeX = wallTexture_.getSize().x / 64;
    int sizeY = wallTexture_.getSize().y / 64;
    for (int i = 0; i < sizeY; ++i) {
        int offsetY = i * 64;
        for (int j = 0; j < sizeX; ++j) {
            int offsetX = j * 64;
            wall.setTextureRect(sf::IntRect(offsetX, offsetY, 1, 64));
            walls.push_back(wall);
        }
    }
}
