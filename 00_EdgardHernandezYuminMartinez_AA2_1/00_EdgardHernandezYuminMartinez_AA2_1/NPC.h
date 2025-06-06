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
	static const int s_numNpc = 31;

public:
	int npc_PosX[s_numNpc];
	int npc_PosY[s_numNpc];
	int npc_Power[s_numNpc];
	int npc_Life[s_numNpc];
	bool npc_Alive[s_numNpc];
	bool npc_neutral[s_numNpc];
	bool npc_Attacked[s_numNpc] = { false };
	
	int bsLife = 500;
	int bs_PosX;
	int bs_PosY;
	bool bsAlife = true;
	bool bsAttacked = false;
	NPC();
    NPC(const FileRead&);
	
	int GetNpcLosSantos() const 
	{
		return m_npcLosSantos;
	}
	int GetMaxMoneySantos() const
	{ 
		return m_maxMoneySantos;
	}
	int GetLifeNpcSantos() const
	{ 
		return m_lifeNpcSantos; 
	}
	int GetPowerNpcSantos() const
	{ 
		return m_powerNpcSantos;
	}

	int GetNpcSanFierro() const 
	{
		return m_npcSanFierro;
	}
	int GetMaxMoneySanFierro() const 
	{ 
		return m_maxMoneySanFierro; 
	}
	int GetLifeNpcSanFierro() const
	{ 
		return m_lifeNpcSanFierro;
	}
	int GetPowerNpcSanFierro() const 
	{ 
		return m_powerNpcSanFierro;
	}

	int GetNpcLasVenturas() const 
	{ 
		return m_npcLasVenturas;
	}
	int GetMaxMoneyLasVenturas() const 
	{ 
		return m_maxMoneyLasVenturas;
	}
	int GetLifeNpcLasVenturas() const 
	{ 
		return m_lifeNpcLasVenturas;
	}
	int GetPowerNpcLasVenturas() const 
	{
		return m_powerNpcLasVenturas; 
	}
	int GetNPC() const 
	{ 
		return m_npcTotal; 
	}

	void ResetBs()
	{
		bsLife = 500;
		bsAlife = true;
		bsAttacked = false;
	}
	int getBSLife() const 
	{ 
		return bsLife;
	}
	int getBSPower() const 
	{ 
		return bsPower;
	}

	int GetTimeToHit() const 
	{ 
		return timeToHit; 
	}
	
	void NpcDamage(int, int);
	void BsDamage(int);

};

