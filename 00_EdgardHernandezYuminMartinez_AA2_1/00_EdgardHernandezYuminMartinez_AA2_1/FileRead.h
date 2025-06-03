#pragma once
#include <iostream>
class FileRead
{
private:
	int filas;
	int columnas;
	int lifeCJ;
	int powerCJ;
	int totalToSanFierro;
	int totalToLasVenturas;
	int npcLosSantos;
	int maxMoneySantos;
	int lifeNpcSantos;
	int powerNpcSantos;
	int npcSanFierro;
	int maxMoneySanFierro;
	int lifeNpcSanFierro;
	int powerNpcSanFierro;
	int limitLosSantos;
	int limitSanFierro;
	int totalNpc;
		
	int NumCarSantos;
	int NumCarSanFierro;
	//int NumCarLasVenturas;

public:
	FileRead();	
	int getFilas() const { return filas; }
	int getColumnas() const { return columnas; }
	int getLifeCJ() const { return lifeCJ; }
	int getPowerCJ() const { return powerCJ; }
	int getTotalToSanFierro() const { return totalToSanFierro; }
	int getTotalToLasVenturas() const { return totalToLasVenturas; }
	int getNpcLosSantos() const { return npcLosSantos; }
	int getMaxMoneySantos() const { return maxMoneySantos; }
	int getLifeNpcSantos() const { return lifeNpcSantos; }
	int getPowerNpcSantos() const { return powerNpcSantos; }
	int getNpcSanFierro() const { return npcSanFierro; }
	int getMaxMoneySanFierro() const { return maxMoneySanFierro; }
	int getLifeNpcSanFierro() const { return lifeNpcSanFierro; }
	int getPowerNpcSanFierro() const { return powerNpcSanFierro; }
	int getLimitLosSantos() const { return limitLosSantos; }
	int getLimitSanFierro() const { return limitSanFierro; }
	int getTotalNpc() const { return totalNpc; }
	int getNumCarSantos() const { return NumCarSantos; }
	int getNumCarSanFierro() const { return NumCarSanFierro; }

};
