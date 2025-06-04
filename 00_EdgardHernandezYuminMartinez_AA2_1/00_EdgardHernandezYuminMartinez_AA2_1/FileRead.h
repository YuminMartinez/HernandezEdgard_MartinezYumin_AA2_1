#pragma once
#include <iostream>
class FileRead
{
private:
	// Para el mapa
	int filas;
	int columnas;
	// Para CJ
	int lifeCJ;
	int powerCJ;
	// Peaje para San Fierro y Las Venturas
	int totalToSanFierro;
	int totalToLasVenturas;
	// Stats de NPCs en Los Santos
	int npcLosSantos;
	int maxMoneySantos;
	int lifeNpcSantos;
	int powerNpcSantos;
	// Stats de NPCs en San Fierro
	int npcSanFierro;
	int maxMoneySanFierro;
	int lifeNpcSanFierro;
	int powerNpcSanFierro;
	// Stats de NPCs en Las Venturas 
	int npcLasVenturas;
	int maxMoneyLasVenturas;
	int lifeNpcLasVenturas;
	int powerNpcLasVenturas;
	// Límites de las ciudades
	int limitLosSantos;
	int limitSanFierro;
	// Total de NPCs
	int totalNpc;
	// Número de coches en cada ciudad
	int NumCarSantos;
	int NumCarSanFierro;
	int NumCarLasVenturas;

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

	int getNpcLasVenturas() const { return npcLasVenturas; }
	int getMaxMoneyLasVenturas() const { return maxMoneyLasVenturas; }
	int getLifeNpcLasVenturas() const { return lifeNpcLasVenturas; }
	int getPowerNpcLasVenturas() const { return powerNpcLasVenturas; }

	int getLimitLosSantos() const { return limitLosSantos; }
	int getLimitSanFierro() const { return limitSanFierro; }

	int getTotalNpc() const { return totalNpc; }
	int getNumCarSantos() const { return NumCarSantos; }
	int getNumCarSanFierro() const { return NumCarSanFierro; }

};
