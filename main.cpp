#include "Headers.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Textures.h"

int main() {
    Textures::mTextures.load(Textures::WEAPON_PISTOL, "textures/weapons1.png");
    Game game;
    World world;
    world.loadLevel();
    world.player.setPosition(sf::Vector2f(2, 2));
    world.player.setDir(sf::Vector2f(1, 0));
    game.run(world);
    return 0;
}
