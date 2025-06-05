#include "Util.h"
#include "Player.h"
#include "Game.h"
#include "Map.h"

Map::Map(const FileRead& fileRead)
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
Map::~Map() 
{
    if (m_Type) 
    {
        for (int i = 0; i < m_filas; ++i) 
        {
            delete[] m_Type[i];
        }
        delete[] m_Type;
    }
}

