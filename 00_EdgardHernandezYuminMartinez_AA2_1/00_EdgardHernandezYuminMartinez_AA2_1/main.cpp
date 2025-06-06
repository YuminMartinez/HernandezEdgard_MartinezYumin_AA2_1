#include "Util.h"
#include "Game.h"
const int NUM_FPS = 60 ;
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
    game.m_player.StatsCJ(game.m_fileRead.getLifeCJ(), game.m_fileRead.getPowerCJ());
	game.SetPlayer();
    game.PrintInit();
	Sleep(timeToWait); 
    
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
            if (game.m_NPC.bsAlife == false || game.m_player.GetCJDead() == true || game.acrossNoMoney == true)
            {
				
				if (game.m_NPC.bsAlife == false)
				{
					std::cout << "Has derrotado a Big Smoke, felicidades!" << std::endl;
                    Sleep(5000);
				}
				else if (game.m_player.GetCJDead() == true)
				{
					std::cout << "CJ ha muerto. Game Over." << std::endl;
                    Sleep(5000);
				}
				else if (game.acrossNoMoney == true)
				{
					std::cout << "La policia te ha detenido  Game Over." << std::endl;
					Sleep(5000);
				}
                game.IsDead = true;
                game.startGame = false;
                game.acrossNoMoney = false;
            }
            if (game.IsDead == true)
            {
				game.ResetGame();
            }

        }
    }
	
	
}