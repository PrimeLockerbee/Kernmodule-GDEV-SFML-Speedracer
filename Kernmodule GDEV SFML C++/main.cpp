#include "Game.h";
#include "Time.h"

int main()
{
    // Since game uses default constructor, is it better just do 'Game game;' ?
    Game game = Game();

    float oldTime = 0;
    while (game.isRunning())
    {
        // Update
        Time::calculateDeltaTime();
        game.onUpdate();
    }

    return 0;
}