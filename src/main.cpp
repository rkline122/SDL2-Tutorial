#include "Game.hpp"
#include "iostream"

int main(int argc, char* argv[]) {
    Game game;

    if (!game.Init()) {
        return 1;
    }

    game.Run();
    game.Clean();

    return 0;
}
