#include "Game.h";
#include "Time.h"

int main()
{
    Game g_Game = Game();

    while (g_Game.IsRunning())
    {
        //Updates the game as long as it is running
        Time::CalculateDeltaTime();
        g_Game.OnUpdate();
    }

    return 0;
}