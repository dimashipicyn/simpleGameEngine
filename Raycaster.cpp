//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Raycaster.hpp"
#include "GameObject.hpp"

Raycaster::Raycaster(int nRays) : rays_(nRays), nRays_(nRays) {}

Raycaster::~Raycaster() {

}

const Raycaster::Ray& Raycaster::getRay(int n) const {
    return rays_[n];
}

int Raycaster::getNRays() const {
    return nRays_;
}

float dist(sf::Vector2f start, sf::Vector2f end)
{
    float a = start.x - end.x;
    float b = start.y - end.y;
    return sqrt(a * a + b * b);
}

Raycaster::Ray norm(const std::vector<std::string> &map, sf::Vector2f vec, sf::Vector2f dir)
{
    Raycaster::Ray  ray = {};
    bool  side;
    int   mapX = (int)vec.x;
    int   mapY = (int)vec.y;
    float stepX;
    float stepY;
    float sx;
    float sy;
    float dx = abs(1 / dir.x);
    float dy = abs(1 / dir.y);
    if (dir.x < 0) {
        stepX = -1;
        sx = (vec.x - mapX) * dx;
    } else {
        stepX = 1;
        sx = (mapX + 1.0f - vec.x) * dx;
    }
    if (dir.y < 0) {
        stepY = -1;
        sy = (vec.y - mapY) * dy;
    } else {
        stepY = 1;
        sy = (mapY + 1.0f - vec.y) * dy;
    }
    for (int i = 0; i < 50; ++i) {
        if (sx < sy) {
            sx += dx;
            mapX += stepX;
            side = false;
        } else {
            sy += dy;
            mapY += stepY;
            side = true;
        }
        char sym = map[mapY][mapX];
        if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", sym)) {
            float len = side == 0 ? sx - dx : sy - dy;
            ray = {sf::Vector2f(sx, sy), dir,  len, sym, side};
            break;
        }
    }
    return ray;
}

sf::Vector2f normalize(sf::Vector2f vec)
{
    float inv_length = 1.0f / sqrt(vec.x * vec.x + vec.y * vec.y);
    return (vec * inv_length);
}

sf::Vector2f rotate(sf::Vector2f rot, float a);

void Raycaster::raycasting(const std::vector<std::string> &map, GameObject gameObject)
{
    sf::Vector2f    dir;
    dir = normalize(gameObject.getDir());
    sf::Vector2f    plane = rotate(dir * 0.5f, M_PI_2);
    sf::Vector2f    rayDir;

    for (int i = 0; i < nRays_; ++i) {
        double nRay = 2 * i / static_cast<double>(nRays_) - 1;
        rayDir.x = dir.x + plane.x * nRay;
        rayDir.y = dir.y + plane.y * nRay;
        rays_[i] = norm(map, gameObject.getPosition(), rayDir);
    }
}