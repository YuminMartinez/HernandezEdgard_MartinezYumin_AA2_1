#include "Util.h"
NPC::NPC(const FileRead& fileread)
{
	m_npcLosSantos = fileread.getNpcLosSantos();
	m_maxMoneySantos = fileread.getMaxMoneySantos();
	m_lifeNpcSantos = fileread.getLifeNpcSantos();
	m_powerNpcSantos = fileread.getPowerNpcSantos();
	m_npcSanFierro = fileread.getNpcSanFierro();
	m_maxMoneySanFierro = fileread.getMaxMoneySanFierro();
	m_lifeNpcSanFierro = fileread.getLifeNpcSanFierro();
	m_powerNpcSanFierro = fileread.getPowerNpcSanFierro();
	m_npcLasVenturas = fileread.getNpcLasVenturas();
	m_maxMoneyLasVenturas = fileread.getMaxMoneyLasVenturas();
	m_lifeNpcLasVenturas = fileread.getLifeNpcLasVenturas();
	m_powerNpcLasVenturas = fileread.getPowerNpcLasVenturas();
	m_npcTotal = m_npcLosSantos + m_npcSanFierro + m_npcLasVenturas;
	
	

}
void NPC::npcDamage(int dmg, int index)
{
	npc_Life[index] -= dmg;
	if (npc_Life[index] <= 0)
	{
		npc_Alive[index] = false;
		npc_Attacked[index] = false;
		npc_Life[index] = 0;
	}
	if (npc_neutral[index] == false)
	{
		npc_Attacked[index] = true; 
	}
}
void NPC::BsDamage(int dmg)
{
	bsLife -= dmg;
	bsAttacked = true; 
	if (bsLife <= 0)
	{
		bsAlife = false;
	}	
}


