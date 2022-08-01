#include "Game.h";
#include "Time.h"

int main()
{
    Game game = Game();

    while (game.IsRunning())
    {
        //Updates the game
        Time::CalculateDeltaTime();
        game.OnUpdate();
    }

    return 0;
}