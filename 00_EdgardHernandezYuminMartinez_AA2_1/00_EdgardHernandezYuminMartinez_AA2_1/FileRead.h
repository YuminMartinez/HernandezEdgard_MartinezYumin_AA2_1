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

	int GetFilas() const { return filas; }
	int GetColumnas() const { return columnas; }

	int GetLifeCJ() const { return lifeCJ; }
	int GetPowerCJ() const { return powerCJ; }

	int GetTotalToSanFierro() const { return totalToSanFierro; }
	int GetTotalToLasVenturas() const { return totalToLasVenturas; }

	int GetNpcLosSantos() const { return npcLosSantos; }
	int GetMaxMoneySantos() const { return maxMoneySantos; }
	int GetLifeNpcSantos() const { return lifeNpcSantos; }
	int GetPowerNpcSantos() const { return powerNpcSantos; }

	int GetNpcSanFierro() const { return npcSanFierro; }
	int GetMaxMoneySanFierro() const { return maxMoneySanFierro; }
	int GetLifeNpcSanFierro() const { return lifeNpcSanFierro; }
	int GetPowerNpcSanFierro() const { return powerNpcSanFierro; }

	int GetNpcLasVenturas() const { return npcLasVenturas; }
	int GetMaxMoneyLasVenturas() const { return maxMoneyLasVenturas; }
	int GetLifeNpcLasVenturas() const { return lifeNpcLasVenturas; }
	int GetPowerNpcLasVenturas() const { return powerNpcLasVenturas; }

	int GetLimitLosSantos() const { return limitLosSantos; }
	int getLimitSanFierro() const { return limitSanFierro; }

	int getTotalNpc() const { return totalNpc; }
	int getNumCarSantos() const { return NumCarSantos; }
	int getNumCarSanFierro() const { return NumCarSanFierro; }

};
