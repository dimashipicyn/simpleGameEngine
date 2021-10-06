#include "Headers.hpp"
#include "Engine.hpp"
#include "GameActor.hpp"
#include "World.hpp"
#include "Raycaster.hpp"

int main() {
    Engine engine;
    World world;
    world.loadLevel();
    world.player.setPosition(sf::Vector2f(2, 2));
    world.player.setDir(sf::Vector2f(1, 0));
    engine.gameLoop(world);
    return 0;
}
