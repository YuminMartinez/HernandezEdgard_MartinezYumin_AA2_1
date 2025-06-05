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
public:
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
	int npc_PosX[31];
	int npc_PosY[31];
	bool npc_Alive[31];
	
};

