#pragma once
#include "Util.h"
#include "FileRead.h"
class Player;
enum class objectType
{
    PLAYER_UP,
    PLAYER_DOWN,
    PLAYER_LEFT,
    PLAYER_RIGHT,
    NPC,
    MONEY,
    LIMIT,
    CAR,
    PEAJE,
    BIGSMOKE,
	DEFAULT
};
class Map 
{
private:
	// Dimensiones del mapa
    int m_filas;
    int m_columnas;
	// Coste de peaje
    int m_totalToSanFierro;
    int m_totalToLasVenturas;
	
	// Límites de las ciudades
    int m_limitLosSantos;
    int m_limitSanFierro;    
	// Coches en cada ciudad
    int NumCarSantos = 3;
    int NumCarSanFierro = 3;
    int NumCarLasVenturas = 3;

public:

    objectType** m_Type;
	Map() : m_filas(0), m_columnas(0), m_totalToSanFierro(0), m_totalToLasVenturas(0), m_limitLosSantos(0), m_limitSanFierro(0), m_Type(nullptr) {}
    Map(const FileRead& fileRead);
    ~Map();
    
    int getLimitLosSantos() const 
    {
        return m_limitLosSantos; 
    }
    int getLimitSanFierro() const
    {
        return m_limitSanFierro;
    }
    int getFilas() const 
    { 
        return m_filas;
    }
    int getColumnas() const 
    { 
        return m_columnas; 
    }
	int getTotalToSanFierro() const
	{
		return m_totalToSanFierro;
	}
	int getTotalToLasVenturas() const
	{
		return m_totalToLasVenturas;
	}

    
};