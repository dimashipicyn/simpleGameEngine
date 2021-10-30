//
// Created by Дима Щипицын on 29/10/2021.
//

#ifndef ENGINE_PLAYER_H
#define ENGINE_PLAYER_H
#include "GameObject.hpp"

class Player : public GameObject {
public:
    enum WeaponType {
        KNOCK,
        PISTOL
    };
};


#endif //ENGINE_PLAYER_H
