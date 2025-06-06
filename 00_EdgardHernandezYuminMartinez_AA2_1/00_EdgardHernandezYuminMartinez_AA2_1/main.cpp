#include "Util.h"
#include "Game.h"
const int NUM_FPS = 30 ;
const int timeToWait = 3000;
int numRandom(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void CleanScreen() {
	system("cls");  

}


int main()
{
    srand(time(NULL));

    Game game;
    game.m_player.SetPos(game.m_fileRead.getFilas() - 1, game.m_fileRead.getLimitLosSantos() - 1);
    game.PrintInit();
	Sleep(timeToWait); 
    game.m_player.StatsCJ(game.m_fileRead.getLifeCJ(), game.m_fileRead.getPowerCJ());
    game.SetPlayer();

    auto lastAttackTime = std::chrono::steady_clock::now();

    while (game.finish == false)
    {
        if (game.IsDead == true)
        {
            CleanScreen();
            game.Menu();
            Sleep(1000 / NUM_FPS);
        }
        else
        {
            CleanScreen();

            game.PlayerInPut();
            game.NPCMoviment();
            

            // Verifica si ha pasado 1 segundo desde el último ataque
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastAttackTime);
            if (elapsed.count() >= game.m_NPC.GetTimeToHit())
            {
                game.NPCMoviment();
                game.AttackNPC();
                lastAttackTime = now;
            }
            game.PrintMap();
            Sleep(1000 / NUM_FPS); // Control de framerate
        }
    }
	
	/*while (game.finish == false)
	{
		
		CleanScreen();
		//INPUT
		game.PlayerInPut();
		
		//UPDATE
		game.NPCMoviment();

		//RENDER
		game.printMap();
	
		//FRAME CONTROL
		Sleep(1000 / NUM_FPS);
	}*/
}