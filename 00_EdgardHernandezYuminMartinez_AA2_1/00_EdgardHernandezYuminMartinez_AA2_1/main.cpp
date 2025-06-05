#include "Util.h"
#include "Game.h"
const int NUM_FPS =30 ;
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
	game.m_player.StatsCJ(game.m_fileRead.getLifeCJ(), game.m_fileRead.getPowerCJ());
	game.SetPlayer();
	Sleep(timeToWait);
	//game.m_fileRead;
	//game.m_map;
	//game.m_player;
	//game.m_NPC;
	//game.CreateNPC();
	
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
			game.PrintMap();
			Sleep(1000 / NUM_FPS);
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