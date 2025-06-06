#pragma once
#include <iostream>
#include "NPC.h"
#include "Player.h"
#include "Map.h"
#include "Car.h"
#include "FileRead.h"
#include <chrono>
#include <thread>
class Game
{

private:
	
public:
	FileRead m_fileRead; 
	Map m_map;
	Player m_player;
	NPC m_NPC;
	Car m_car;
	Game()
		: m_fileRead(),
		m_map(m_fileRead),
		m_player(),
		m_NPC(m_fileRead),
		m_car()
	{
		CreateNPC();
		
	}
	
	int MapPos = 0; // 0 = Los Santos, 1 = San Fierro, 2 = Las Venturas
	int menuOption = -1;
	int iteration = 0; // Contador de iteraciones para el movimiento de NPCs
	bool finish = false;
	bool startGame = false;
	bool IsDead = true;
	void ResetGame();
	
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
	void SetPlayer();
	void PrintMap() const;
	void CreateNPC();
	void NPCMoviment();
	void AttackNPC();
	~Game();
};



