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
	FileRead()
	{
		{
			std::ifstream myFile("config.txt");
			if (!myFile.is_open())
			{
				std::cout << "Error al abrir config.txt\n";
				return;
			}
			std::string line;
			int lineNumber = 0;
			while (std::getline(myFile, line))
			{
				std::stringstream ss(line);
				std::string item;
				switch (lineNumber)
				{
				case 0:
					if (std::getline(ss, item, ';')) filas = std::stoi(item);
					if (std::getline(ss, item, ';')) columnas = std::stoi(item);

					break;
				case 1:
					if (std::getline(ss, item, ';')) lifeCJ = std::stoi(item);
					if (std::getline(ss, item, ';')) powerCJ = std::stoi(item);

					break;
				case 2:
					if (std::getline(ss, item, ';')) totalToSanFierro = std::stoi(item);
					if (std::getline(ss, item, ';')) totalToLasVenturas = std::stoi(item);

					break;
				case 3:
					if (std::getline(ss, item, ';')) npcLosSantos = std::stoi(item);
					if (std::getline(ss, item, ';')) maxMoneySantos = std::stoi(item);
					if (std::getline(ss, item, ';')) lifeNpcSantos = std::stoi(item);
					if (std::getline(ss, item, ';')) powerNpcSantos = std::stoi(item);

					break;
				case 4:
					if (std::getline(ss, item, ';')) npcSanFierro = std::stoi(item);
					if (std::getline(ss, item, ';')) maxMoneySanFierro = std::stoi(item);
					if (std::getline(ss, item, ';')) lifeNpcSanFierro = std::stoi(item);
					if (std::getline(ss, item, ';')) powerNpcSanFierro = std::stoi(item);

					break;
				case 5:
					if (std::getline(ss, item, ';')) npcLasVenturas = std::stoi(item);
					if (std::getline(ss, item, ';')) maxMoneyLasVenturas = std::stoi(item);
					if (std::getline(ss, item, ';')) lifeNpcLasVenturas = std::stoi(item);
					if (std::getline(ss, item, ';')) powerNpcLasVenturas = std::stoi(item);

					break;
				default:
					std::cout << "Línea desconocida en config.txt: " << lineNumber << "\n";
				}
				lineNumber++;
			}
			limitLosSantos = columnas / 3;
			limitSanFierro = limitLosSantos * 2;
		}
	}

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
