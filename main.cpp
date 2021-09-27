#include "Headers.hpp"
#include "Engine.hpp"
#include "GameActor.hpp"


int main() {
    Engine engine;
    GameActor player;
    engine.gameLoop(player);
    return 0;
}
