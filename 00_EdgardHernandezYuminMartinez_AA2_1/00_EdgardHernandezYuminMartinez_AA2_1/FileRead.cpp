#include "FileRead.h"
#include "Util.h"
FileRead::FileRead()
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
			if (std::getline(ss, item, ';')) totalToSanFierro = std::stoi(item);
			break;
		case 2:
			if (std::getline(ss, item, ';')) totalToLasVenturas = std::stoi(item);
			if (std::getline(ss, item, ';')) npcLosSantos = std::stoi(item);
			if (std::getline(ss, item, ';')) maxMoneySantos = std::stoi(item);
			break;
		case 3:
			if (std::getline(ss, item, ';')) lifeNpcSantos = std::stoi(item);
			if (std::getline(ss, item, ';')) powerNpcSantos = std::stoi(item);
			if (std::getline(ss, item, ';')) npcSanFierro = std::stoi(item);
			break;
		case 4:
			if (std::getline(ss, item, ';')) maxMoneySanFierro = std::stoi(item);
			if (std::getline(ss, item, ';')) lifeNpcSanFierro = std::stoi(item);
			if (std::getline(ss, item, ';')) powerNpcSanFierro = std::stoi(item);
			break;
		case 5:
			if (std::getline(ss, item, ';')) limitLosSantos = std::stoi(item);
			if (std::getline(ss, item, ';')) limitSanFierro = std::stoi(item);
			break;
		default:
			std::cerr << "Línea desconocida en config.txt\n";
		}
	}
}
