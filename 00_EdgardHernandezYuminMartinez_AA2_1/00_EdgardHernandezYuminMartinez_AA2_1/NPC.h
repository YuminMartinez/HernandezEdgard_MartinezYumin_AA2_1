#pragma once
#include "Util.h"
#include "FileRead.h"
class NPC
{
    // Stats de NPCs en Los Santos
    int m_npcLosSantos;
    int m_maxMoneySantos;
    int m_lifeNpcSantos;
    int m_powerNpcSantos;
    // Stats de NPCs en San Fierro
    int m_npcSanFierro;
    int m_maxMoneySanFierro;
    int m_lifeNpcSanFierro;
    int m_powerNpcSanFierro;
    // Stats de NPCs en Las Venturas
    int m_npcLasVenturas;
    int m_maxMoneyLasVenturas;
    int m_lifeNpcLasVenturas;
    int m_powerNpcLasVenturas;
	int m_npcTotal;
	int timeToHit = 1000; 

	int bsPower = 45;


public:
	int npc_PosX[31];
	int npc_PosY[31];
	int npc_Power[31];
	int npc_Life[31];
	bool npc_Alive[31];
	bool npc_neutral[31];
	bool npc_Attacked[31] = { false };
	
	int bsLife = 500;
	int bs_PosX;
	int bs_PosY;
	bool bsAlife = true;
	bool bsAttacked = false;
	NPC();
    NPC(const FileRead&);
	
	int getNpcLosSantos() const { return m_npcLosSantos; }
	int getMaxMoneySantos() const { return m_maxMoneySantos; }
	int getLifeNpcSantos() const { return m_lifeNpcSantos; }
	int getPowerNpcSantos() const { return m_powerNpcSantos; }

	int getNpcSanFierro() const { return m_npcSanFierro; }
	int getMaxMoneySanFierro() const { return m_maxMoneySanFierro; }
	int getLifeNpcSanFierro() const { return m_lifeNpcSanFierro; }
	int getPowerNpcSanFierro() const { return m_powerNpcSanFierro; }

	int getNpcLasVenturas() const { return m_npcLasVenturas; }
	int getMaxMoneyLasVenturas() const { return m_maxMoneyLasVenturas; }
	int getLifeNpcLasVenturas() const { return m_lifeNpcLasVenturas; }
	int getPowerNpcLasVenturas() const { return m_powerNpcLasVenturas; }
	int getNPC() const { return m_npcTotal; }

	void ResetBs()
	{
		bsLife = 500;
		bsAlife = true;
		bsAttacked = false;
	}
	int getBSLife() const { return bsLife; }
	int getBSPower() const { return bsPower; }

	int GetTimeToHit() const { return timeToHit; }
	
	void npcDamage(int, int);
	void BsDamage(int);

};

