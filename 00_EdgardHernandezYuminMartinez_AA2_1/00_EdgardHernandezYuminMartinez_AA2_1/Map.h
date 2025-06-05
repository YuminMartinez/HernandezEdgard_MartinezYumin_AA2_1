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
    Map(const FileRead& fileRead)
    {
        m_filas = fileRead.getFilas();
        m_columnas = fileRead.getColumnas();
        m_totalToSanFierro = fileRead.getTotalToSanFierro();
        m_totalToLasVenturas = fileRead.getTotalToLasVenturas();
        m_limitLosSantos = fileRead.getLimitLosSantos();
        m_limitSanFierro = fileRead.getLimitSanFierro();
        // Inicialización de la matriz
        m_Type = new objectType * [m_filas];
        for (int i = 0; i < m_filas; ++i) {
            m_Type[i] = new objectType[m_columnas];
            for (int j = 0; j < m_columnas; ++j) {
                // 1. Por defecto, todo es transitable (DEFAULT)
                m_Type[i][j] = objectType::DEFAULT;

                // 2. Todos los bordes son LIMIT 
                if (i == 0 || j == 0 || i == m_filas - 1 || j == m_columnas - 1 || j == m_limitLosSantos || j == m_limitSanFierro) {
                    m_Type[i][j] = objectType::LIMIT;
                }

                // 3.Colocar passaje
                if (i == 40 && j == m_limitLosSantos) {
                    m_Type[i][j] = objectType::PEAJE;
                }

                if (i == 10 && j == m_limitSanFierro)
                {
                    m_Type[i][j] = objectType::PEAJE;
                }
            }
        }
    }
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