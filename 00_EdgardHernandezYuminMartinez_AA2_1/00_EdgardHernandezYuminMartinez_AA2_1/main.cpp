#include "Util.h"
#include "Game.h"
const int NUM_FPS = 100;
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
	game.PrintInit();
	Sleep(timeToWait);
	//game.m_fileRead;
	/*	game.m_map;
	game.m_player;
	game.m_NPC;
	game.CreateNPC();*/
	game.m_fileRead;
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
			game.printMap();
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