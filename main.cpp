#include "Headers.hpp"
#include "Engine.hpp"
#include "GameActor.hpp"
#include "Levels.hpp"
#include "Raycaster.hpp"


int main() {
    Engine engine;
    GameActor player;
    Levels levels;

    player.setPosition(sf::Vector2f(1.5, 1.5));
    engine.gameLoop(player, levels);
    return 0;
}
