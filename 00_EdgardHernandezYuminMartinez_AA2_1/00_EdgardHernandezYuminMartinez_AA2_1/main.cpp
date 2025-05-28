#include "Util.h"
#include "Game.h"
const int NUM_FPS = 100;

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
	game.m_map;
	game.m_player;
	game.m_NPC;
	game.CreateNPC();	

	while (game.finish == false)
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
	}
}