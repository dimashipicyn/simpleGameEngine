//
// Created by Дима Щипицын on 05/10/2021.
//

#include "World.hpp"
#include "ResourceHolder.h"
#include "Textures.h"

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
    mWallTexture.loadFromFile("textures/walls.png");
    mGameObjectTexture.loadFromFile("textures/hitler1.BMP");
    sf::Sprite wall;
    wall.setTexture(mWallTexture);
    int sizeX = mWallTexture.getSize().x / 64;
    int sizeY = mWallTexture.getSize().y / 64;
    for (int i = 0; i < sizeY; ++i) {
        int offsetY = i * 64;
        for (int j = 0; j < sizeX; ++j) {
            int offsetX = j * 64;
            wall.setTextureRect(sf::IntRect(offsetX, offsetY, 1, 64));
            walls.push_back(wall);
        }
    }
}

World::World() :
player(new PlayerInputComponent(), 0, new PlayerGraphicsComponent()),
mRaycaster(800)
{
}

void World::update() {
    player.update();
}

void World::render(sf::RenderWindow &window) {
    mRaycaster.raycasting(map, player);
    drawWall(window);
    player.render(window);
}


float scalarMul(sf::Vector2f one, sf::Vector2f two)
{
    return one.x * two.x + one.y * two.y;
}

void World::drawWall(sf::RenderWindow &window)
{
    sf::Sprite      wall;
    sf::IntRect     wallRect;
    sf::Vector2f    posPlr   = player.getPosition();
    int             winSizeY = static_cast<int>(window.getSize().y);
    for (int i = 0; i < mRaycaster.getNRays(); ++i) {
        Raycaster::Ray ray = mRaycaster.getRay(i);
        int height = winSizeY / ray.len;
        float scale = winSizeY / 64 / ray.len;
        float offset = ray.side == 0 ? posPlr.y + ray.len * ray.dir.y : posPlr.x + ray.len * ray.dir.x;
        offset -= floor(offset);
        wall = walls[ray.wallnum - 'A'];
        wallRect = wall.getTextureRect();
        wallRect.left = wallRect.left + 64 * offset;
        wall.setTextureRect(wallRect);
        float y = roundf((winSizeY - height) / 2.0);
        wall.setPosition(sf::Vector2f(i, y));
        wall.setScale(sf::Vector2f(1, scale));
        if (ray.side)
            wall.setColor(sf::Color(255, 255, 255, 200));
        else
            wall.setColor(sf::Color(255, 255, 255, 255));
        window.draw(wall);
    }
}
