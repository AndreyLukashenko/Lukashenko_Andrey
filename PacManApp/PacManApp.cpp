#include <iostream>
#include "Game.hpp"

int main()
{
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->run();
    return 0;
}
