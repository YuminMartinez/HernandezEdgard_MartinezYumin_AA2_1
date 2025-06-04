#pragma once
#include <iostream>
#include "NPC.h"
#include "Player.h"
#include "Map.h"
#include "Car.h"
#include "FileRead.h"
class Game
{

private:
	
public:
	FileRead m_fileRead;
	Map m_map;
	Player m_player;
	NPC m_NPC;
	Car m_car;
	int menuOption = 0;
	bool finish = false;
	bool startGame = false;
	bool IsDead = true;
	Player getPlayer() 
	{ 
		return m_player;
	}
	Map getMap()
	{ 
		return m_map;
	}
	NPC getNPC()
	{
		return m_NPC;
	}
	void PrintInit();
	void Menu();
	void PlayerInPut();
	void setPlayer();
	void printMap() const;
	void CreateNPC();
	void NPCMoviment();
};



