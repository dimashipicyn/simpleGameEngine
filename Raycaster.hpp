//
// Created by Дима Щипицын on 27/09/2021.
//

#ifndef ENGINE_RAYCASTER_HPP
#define ENGINE_RAYCASTER_HPP
#include "Headers.hpp"

class GameObject;

class Raycaster {
public:
    Raycaster(int nRays);
    ~Raycaster();
    void    raycasting(const std::vector<std::string> &map, GameObject gameObject);

    struct Ray {
        sf::Vector2f    pos;
        sf::Vector2f    dir;
        float           len;
        char            wallnum;
        bool            side;
    };
    const Ray&  getRay(int n) const;
    int         getNRays() const;

private:
    std::vector<Ray>    rays_;
    int                 nRays_;
};


#endif //ENGINE_RAYCASTER_HPP
