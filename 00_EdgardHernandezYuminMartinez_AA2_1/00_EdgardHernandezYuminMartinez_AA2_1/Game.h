#pragma once
#include <iostream>
#include "NPC.h"
#include "Player.h"
#include "Map.h"
#include "Car.h"

class Game
{

private:
	
public:
	Map m_map;
	Player m_player;
	NPC m_NPC;
	Car m_car;

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

	bool finish = false;
	void PlayerInPut();
	void setPlayer();
	void printMap() const;
	void CreateNPC();
	void NPCMoviment();
};



