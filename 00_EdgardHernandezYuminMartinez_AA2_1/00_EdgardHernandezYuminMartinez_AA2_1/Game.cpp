#include "Game.h"
#include <Windows.h> 

int Game::GetCurrentZone()
{
    if (m_player.getPosY() < m_map.getLimitLosSantos())
    {
        return 0; // Los Santos
    }
    else if (m_player.getPosY() >= m_map.getLimitLosSantos() && m_player.getPosY() < m_map.getLimitSanFierro())
    {
        return 1; // San Fierro
    }
    else if (m_player.getPosY() >= m_map.getLimitSanFierro())
    {
        return 2; // Las Venturas
    }
    return 0; // Default
}
bool Game::HandlePeaje()
{

    // Definir costos del peaje según la zona
    int peajeCosts[2] = { m_fileRead.getLimitLosSantos(), m_fileRead.getLimitSanFierro() }; // Los Santos, San Fierro, Las Venturas
    int peajeCost = peajeCosts[GetCurrentZone()];

    // Verificar si el jugador tiene suficiente dinero
    if (m_player.getMoney() >= peajeCost)
    {
        // Pagar el peaje
        m_player.subtractMoney(peajeCost);

        // Convertir el peaje a DEFAULT
        m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::DEFAULT;

        return false; // Movimiento permitido
    }
    else if (m_player.getMoney() < peajeCost)
    {
        // No tiene suficiente dinero - Game Over
        

        
        return true; // Movimiento no permitido
    }
}
void Game::KillNpcWithCar()
{
    // 1. Buscar el NPC en lista y marcarlo como muerto
    for (int j = 0; j < m_NPC.GetNPC(); j++)
    {
        if (m_NPC.npc_PosX[j] == m_player.getPosX() && m_NPC.npc_PosY[j] == m_player.getPosY())
        {
            m_NPC.npc_Alive[j] = false;
            break;
        }
    }



    // 3. Buscar una celda libre alrededor para soltar dinero
    int directions[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    bool dineroSoltado = false;
    for (int i = 0; i < 4; ++i)
    {
        int dx = m_player.getPosX() + directions[i][0];
        int dy = m_player.getPosY() + directions[i][1];

        // Verificar límites del mapa
        if (dx >= 0 && dx < m_map.getFilas() && dy >= 0 && dy < m_map.getColumnas())
        {
            if (m_map.m_Type[dx][dy] == objectType::DEFAULT) // Celda libre
            {
                m_map.m_Type[dx][dy] = objectType::MONEY;
                dineroSoltado = true;
                break; // Ya soltamos dinero, salir del ciclo
            }
        }
    }


}
void Game::PrintInit()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|        GRAND THEFT AUTO: Enti city         |" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl << std::endl;
    std::cout << "                Loading game... " << std::endl;
}
void Game::Menu()
{
    if (!startGame)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            menuOption = 0;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            menuOption = 1;
        }
        if (menuOption == 0)
        {
            std::cout << "1. Play <--" << std::endl;
            std::cout << "2. Exit" << std::endl;
        }
        else if (menuOption == 1)
        {
            std::cout << "1. Play" << std::endl;
            std::cout << "2. Exit <--" << std::endl;
        }
        else
        {
			std::cout << "1. Play" << std::endl;
			std::cout << "2. Exit" << std::endl;
        }
        if (GetAsyncKeyState(VK_SPACE) && menuOption == 0)
        {
            startGame = true;
            
			IsDead = false;
        }
        else if (GetAsyncKeyState(VK_SPACE) && menuOption == 1)
        {
            finish = true;
        }
    }
}
void Game::PlayerInPut()
{
    int x = m_player.getPosX();
    int y = m_player.getPosY();

    // Movimiento hacia la izquierda
    if (GetAsyncKeyState(VK_LEFT) & 0x8000 && y > 0)
    {

        if (m_map.m_Type[x][y - 1] == objectType::PEAJE)
        {
            acrossNoMoney = HandlePeaje();
        }

        if (m_player.isInCar())
        {
            if (m_map.m_Type[x][y - 1] == objectType::DEFAULT)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveLeft();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
            }
            else if (m_map.m_Type[x][y - 1] == objectType::NPC)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveLeft();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
                KillNpcWithCar();

            }
        }
        else if (!m_player.isInCar())
        {
            if (m_map.m_Type[x][y - 1] == objectType::DEFAULT)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveLeft();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_LEFT;
            }
            else if (m_map.m_Type[x][y - 1] == objectType::MONEY)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveLeft();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_LEFT;
                if (GetCurrentZone() == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySantos()));
                }
                else if (GetCurrentZone() == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySanFierro()));
                }
                else if (GetCurrentZone() == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneyLasVenturas()));
                }
            }
        }
    }
    // Movimiento hacia arriba
    else if (GetAsyncKeyState(VK_UP) & 0x8000 && x > 0)
    {
        if (m_map.m_Type[x - 1][y] == objectType::PEAJE)
        {
            acrossNoMoney = HandlePeaje();
        }


        if (m_player.isInCar())
        {
            if (m_map.m_Type[x - 1][y] == objectType::DEFAULT)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveForward();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
            }
            else if (m_map.m_Type[x - 1][y] == objectType::NPC)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveRight();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
                KillNpcWithCar();
            }
        }
        else if (!m_player.isInCar())
        {
            if (m_map.m_Type[x - 1][y] == objectType::DEFAULT || m_map.m_Type[x - 1][y] == objectType::PEAJE)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveForward();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_UP;
            }
            else if (m_map.m_Type[x - 1][y] == objectType::MONEY)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveForward();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_UP;
                if (GetCurrentZone() == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySantos()));
                }
                else if (GetCurrentZone() == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySanFierro()));
                }
                else if (GetCurrentZone() == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneyLasVenturas()));
                }
            }
        }
    }
    // Movimiento hacia la derecha
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && y < m_map.getColumnas() - 1)
    {

        if (m_map.m_Type[x][y + 1] == objectType::PEAJE)
        {
            acrossNoMoney = HandlePeaje();
        }

        if (m_player.isInCar())
        {
            if (m_map.m_Type[x][y + 1] == objectType::DEFAULT)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveRight();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
            }
            else if (m_map.m_Type[x][y + 1] == objectType::NPC)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveRight();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
                KillNpcWithCar();
            }
        }
        else if (!m_player.isInCar())
        {
            if (m_map.m_Type[x][y + 1] == objectType::DEFAULT || m_map.m_Type[x][y + 1] == objectType::PEAJE)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveRight();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_RIGHT;
            }
            else if (m_map.m_Type[x][y + 1] == objectType::MONEY)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveRight();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_RIGHT;
                if (GetCurrentZone() == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySantos()));
                }
                else if (GetCurrentZone() == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySanFierro()));
                }
                else if (GetCurrentZone() == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneyLasVenturas()));
                }
            }
        }
    }
    // Movimiento hacia abajo
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && x < m_map.getFilas() - 1)
    {
        if (m_player.isInCar())
        {
            if (m_map.m_Type[x + 1][y] == objectType::DEFAULT || m_map.m_Type[x + 1][y] == objectType::PEAJE)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveBack();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
            }
            else if (m_map.m_Type[x + 1][y] == objectType::NPC)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveBack();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::CAR;
                KillNpcWithCar();
            }
        }
        else if (!m_player.isInCar())
        {
            if (m_map.m_Type[x + 1][y] == objectType::DEFAULT || m_map.m_Type[x + 1][y] == objectType::PEAJE)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveBack();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_DOWN;
            }
            else if (m_map.m_Type[x + 1][y] == objectType::MONEY)
            {
                m_map.m_Type[x][y] = objectType::DEFAULT;
                m_player.moveBack();
                m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_DOWN;
                if (GetCurrentZone() == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySantos()));
                }
                else if (GetCurrentZone() == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneySanFierro()));
                }
                else if (GetCurrentZone() == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.GetMaxMoneyLasVenturas()));
                }
            }
        }
    }
    else
    {
        // Si no se mueve, se mantiene la posición actual
        m_player.SetPosX(x);
        m_player.setPosY(y);
    }

    // Acción de ataque con espacio
    if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !m_player.isInCar())
    {
        int adjacent[4][2] = { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
        // Buscar NPCs adyacentes
        for (int i = 0; i < 4; ++i)
        {
            int targetX = adjacent[i][0];
            int targetY = adjacent[i][1];


            // Verificar si hay un NPC en la posición de ataque
            if (targetX >= 0 && targetX < m_map.getFilas() && targetY >= 0 && targetY < m_map.getColumnas() && (m_map.m_Type[targetX][targetY] == objectType::NPC || m_map.m_Type[targetX][targetY] == objectType::BIGSMOKE))
            {
                // 1. Eliminar el NPC del array
                for (int i = 0; i < m_NPC.GetNPC(); i++)
                {
                    if (m_NPC.npc_PosX[i] == targetX && m_NPC.npc_PosY[i] == targetY)
                    {
                        m_NPC.NpcDamage(m_player.GetPower(), i);
                        if (m_NPC.npc_Alive[i] == false)
                        {
                            m_map.m_Type[targetX][targetY] = objectType::MONEY;
                        }
                        break;
                    }
                }
                if (m_map.m_Type[targetX][targetY] == objectType::BIGSMOKE)
                {
                    m_NPC.BsDamage(m_player.GetPower());

                }

            }
        }
    }

    // Entrar o salir del coche con 'E'
    if (GetAsyncKeyState('E') & 0x8000)
    {
        if (!m_player.isInCar())  // ? Este primer if
        {
            int adjacent[4][2] = { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
            for (int i = 0; i < 4; ++i)
            {
                int ax = adjacent[i][0];
                int ay = adjacent[i][1];
                if (ax >= 0 && ax < m_map.getFilas() && ay >= 0 && ay < m_map.getColumnas())
                {
                    if (m_map.m_Type[ax][ay] == objectType::CAR)
                    {
                        m_map.m_Type[x][y] = objectType::DEFAULT;     // Solo limpia la posición del jugador
                        m_player.SetPosX(ax);                         // Mueve jugador a donde está el coche
                        m_player.setPosY(ay);                         // Mueve jugador a donde está el coche
                        m_player.setInCar(true);
                        m_map.m_Type[ax][ay] = objectType::CAR;
                    }
                }
            }
        }
        else if (m_player.isInCar())
        {
            int adjacent[4][2] = { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
            bool placed = false;
            for (int i = 0; i < 4 && !placed; ++i)
            {
                int ax = adjacent[i][0];
                int ay = adjacent[i][1];
                if (ax >= 0 && ax < m_map.getFilas() && ay >= 0 && ay < m_map.getColumnas())
                {
                    if (m_map.m_Type[ax][ay] == objectType::DEFAULT)
                    {
                        m_map.m_Type[x][y] = objectType::CAR;
                        m_player.SetPosX(ax);
                        m_player.setPosY(ay);
                        m_player.setInCar(false);
                        m_map.m_Type[ax][ay] = objectType::PLAYER_UP; // Jugador mirando hacia arriba al bajarse
                        placed = true;
                    }
                }
            }
        }
    }
}

void Game::PrintMap() const
{
    
    // calcular la posición de inicio para la vista
    int startFila = m_player.getPosX() - m_player.getPlayerViewHeight() / 2;  // Filas (Y)
    int startCol = m_player.getPosY() - m_player.getPlayerViewWidth() / 2;   // Columnas (X)

    // Corregir los límites: asegurarnos de que la vista no se sale del mapa
    if (startFila < 0)
    {
        startFila = 0;
    }
    if (startCol < 0)
    {
        startCol = 0;
    }

    // Asegurarnos de que la vista no se salga del mapa
    if (startFila + m_player.getPlayerViewHeight() > m_map.getFilas())
    {
        startFila = m_map.getFilas() - m_player.getPlayerViewHeight();
    }

    if (startCol + m_player.getPlayerViewWidth() > m_map.getColumnas())
    {
        startCol = m_map.getColumnas() - m_player.getPlayerViewWidth();
    }

    // Dibujar el mapa centrado en el jugador
    for (int fila = 0; fila < m_player.getPlayerViewHeight(); ++fila)
    {
        for (int col = 0; col < m_player.getPlayerViewWidth(); ++col)
        {
            int mapY = startFila + fila; // Fila real en el mapa
            int mapX = startCol + col;   // Columna real en el mapa
            
            if (mapY >= 0 && mapY < m_map.getFilas() && mapX >= 0 && mapX < m_map.getColumnas())
            {
                if (mapY == m_player.getPosX() && mapX == m_player.getPosY())
                {
                    switch (m_map.m_Type[mapY][mapX])
                    {
                    case objectType::PLAYER_UP:
                        std::cout << "^";
                        break;
                    case objectType::PLAYER_DOWN:
                        std::cout << "v";
                        break;
                    case objectType::PLAYER_LEFT:
                        std::cout << "<";
                        break;
                    case objectType::PLAYER_RIGHT:
                        std::cout << ">";
                        break;
                    case objectType::CAR:
                        std::cout << "C";
                        break;
                    }
                }
                else
                {// Marcar al jugador con un símbolo especial (@)

                    switch (m_map.m_Type[mapY][mapX])
                    {
                    case objectType::LIMIT:
                        std::cout << "X";
                        break;
                    case objectType::PLAYER_UP:
                        std::cout << "^";
                        break;
                    case objectType::PLAYER_DOWN:
                        std::cout << "v";
                        break;
                    case objectType::PLAYER_LEFT:
                        std::cout << "<";
                        break;
                    case objectType::PLAYER_RIGHT:
                        std::cout << ">";
                        break;
                    case objectType::NPC:
                        std::cout << "P";
                        break;
                    case objectType::MONEY:
                        std::cout << "$";
                        break;
                    case objectType::CAR:
                        std::cout << "C";
                        break;
                    case objectType::BIGSMOKE:
                        std::cout << "B";
                        break;
                    case objectType::DEFAULT:
                        std::cout << " ";
                        break;
                    case objectType::PEAJE:
                        std::cout << "T";
                        break;
                    default:
                        std::cout << "?";
                        break;
                    }
                }
            }
        }
        std::cout << std::endl;  // Nueva línea por cada fila del mapa
    }

    // Imprimir información de depuración
    std::cout << "\nJugador: (" << m_player.getPosX() << ", " << m_player.getPosY() << ")";
    std::cout << "\nVista: " << m_player.getPlayerViewWidth() << "x" << m_player.getPlayerViewHeight();
    std::cout << "\nMapa: " << m_map.getColumnas() << "x" << m_map.getFilas();
    std::cout << "\nDinero: " << m_player.getMoney() << "$";
	std::cout << "\nVidaCJ: " << m_player.getLife() << std::endl;
	
}
void Game::SetCars()
{
    // LOS SANTOS
    int x = 0;
    int y = 0;
    for (int i = 0; i < m_car.GetNumCarSantos(); i++)
    {
        do
        {
            y = numRandom(1, m_map.getFilas() - 1);  // fila
            x = numRandom(1, m_map.getLimitLosSantos() - 1); // columna dentro de Los Santos
        } while (m_map.m_Type[y][x] != objectType::DEFAULT);

        m_map.m_Type[y][x] = objectType::CAR;
    }

    // San fierro

    for (int i = 0; i < m_car.GetNumCarSanFierro(); i++)
    {
        do
        {
            y = numRandom(1, m_map.getFilas() - 1);  // fila
            x = numRandom(m_map.getLimitLosSantos(), m_map.getLimitSanFierro() - 1); // columna en San Fierro
        } while (m_map.m_Type[y][x] != objectType::DEFAULT);

        m_map.m_Type[y][x] = objectType::CAR;
    }

    //las venturas


    for (int i = 0; i < m_car.GetNumCarLasVenturas(); i++)
    {
        do
        {
            y = numRandom(1, m_map.getFilas() - 1);  // fila
            x = numRandom(m_map.getLimitSanFierro(), m_map.getColumnas() - 1); // columna en Las Venturas
        } while (m_map.m_Type[y][x] != objectType::DEFAULT);

        m_map.m_Type[y][x] = objectType::CAR;
    }


}
void Game::SetPlayer() 
{
   
    m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_UP;
}
void Game::CreateNPC()
{
    for (int i = 0; i < m_NPC.GetNpcLosSantos(); i++)
    {
        do 
        {
            m_NPC.npc_PosX[i] = numRandom(1, m_map.getFilas() - 1);
            m_NPC.npc_PosY[i] = numRandom(1, m_map.getLimitLosSantos() - 1);
        } while (m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio

        m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::NPC;
        m_NPC.npc_Alive[i] = true;
		m_NPC.npc_Power[i] = m_NPC.GetPowerNpcSantos();
		m_NPC.npc_Life[i] = m_NPC.GetLifeNpcSantos();
		int Random = numRandom(0, 2);
        if (Random == 1)
        {
			m_NPC.npc_neutral[i] = true; 
		}
        else
        {
            m_NPC.npc_neutral[i] = false;
        }
		
    }
    for (int i = m_NPC.GetNpcLosSantos(); i < (m_NPC.GetNpcLosSantos() + m_NPC.GetNpcSanFierro()); i++)
    {
        do
        {
            m_NPC.npc_PosX[i] = numRandom(1, m_map.getFilas() - 1);
            m_NPC.npc_PosY[i] = numRandom(m_map.getLimitLosSantos()+1, m_map.getLimitSanFierro() - 1);
        } while (m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio

        m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::NPC;
        m_NPC.npc_Alive[i] = true;
        m_NPC.npc_Power[i] = m_NPC.GetPowerNpcSanFierro();
        m_NPC.npc_Life[i] = m_NPC.GetLifeNpcSanFierro();
        int Random = numRandom(0, 2);
        if (Random == 1)
        {
            m_NPC.npc_neutral[i] = true;
        }
        else
        {
            m_NPC.npc_neutral[i] = false;
        }
        
    }
    for (int i = m_NPC.GetNpcLosSantos() + m_NPC.GetNpcSanFierro(); i < (m_NPC.GetNpcLosSantos() + m_NPC.GetNpcSanFierro() + m_NPC.GetNpcLasVenturas()); i++)
    {
		do
		{
			m_NPC.npc_PosX[i] = numRandom(1, m_map.getFilas() - 1);
			m_NPC.npc_PosY[i] = numRandom(m_map.getLimitSanFierro() + 1, m_map.getColumnas() - 1);
		} while (m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio
		m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::NPC;
		m_NPC.npc_Alive[i] = true;
        m_NPC.npc_Power[i] = m_NPC.GetPowerNpcLasVenturas();
        m_NPC.npc_Life[i] = m_NPC.GetLifeNpcLasVenturas();
        int Random = numRandom(0, 2);
        if (Random == 1)
        {
            m_NPC.npc_neutral[i] = true;
        }
        else
        {
            m_NPC.npc_neutral[i] = false;
        }
        
    }
    do
    {
        m_NPC.bs_PosX = numRandom(1, m_map.getFilas() - 1);
        m_NPC.bs_PosY = numRandom(m_map.getLimitSanFierro() + 1, m_map.getColumnas() - 1);
    } while (m_map.m_Type[m_NPC.bs_PosX][m_NPC.bs_PosY] != objectType::DEFAULT);
	m_NPC.ResetBs();
    m_map.m_Type[m_NPC.bs_PosX][m_NPC.bs_PosY] = objectType::BIGSMOKE;// Asegura que solo spawnean en un lugar donde este vacio
}
void Game::NPCMoviment()
{
	// Mueve a Big Smoke
    if (m_NPC.bsAlife == true)
    {
		bool playerInRangeBS = false;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int checkPosX = m_player.getPosX() + i;
				int checkPosY = m_player.getPosY() + j;
				if (checkPosX == m_NPC.bs_PosX && checkPosY == m_NPC.bs_PosY)
				{
					playerInRangeBS = true;
                    break;
				}
			}
		}
		if (!playerInRangeBS)
		{
			bool moved = false;
			int intentos = 0;
			while (!moved && intentos < 10)
			{
				int newX = m_NPC.bs_PosX;
				int newY = m_NPC.bs_PosY;
				int randomMoviment = numRandom(1, 4);
				switch (randomMoviment)
				{
				case 1: // Arriba
					newX--;
					break;
				case 2: // Abajo
					newX++;
					break;
				case 3: // Izquierda
					newY--;
					break;
				case 4: // Derecha
					newY++;
					break;
				}
				int limiteX = m_map.getFilas() - 1;
				int limiteY = m_map.getColumnas() - 1;
				// Verifica que la posición nueva esté dentro del mapa
				if (newX >= 0 && newX < limiteX && newY >= 0 && newY < limiteY)
				{
					// Verifica que la casilla esté vacía
					if (m_map.m_Type[newX][newY] == objectType::DEFAULT)
					{
						// Libera la casilla anterior
						m_map.m_Type[m_NPC.bs_PosX][m_NPC.bs_PosY] = objectType::DEFAULT;
						// Actualiza posición
						m_NPC.bs_PosX = newX;
						m_NPC.bs_PosY = newY;
						// Marca la casilla como Big Smoke
						m_map.m_Type[newX][newY] = objectType::BIGSMOKE;
						moved = true;
					}
				}
				intentos++;
			}
		}
    }
        for (int p = 0; p < m_NPC.GetNPC(); p++)
        {
            if (m_NPC.npc_Alive[p] == true)
            {
                bool playerInRange[31] = { false };
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int  t = 0;
                        int checkPosX = m_player.getPosX() + i;
                        int checkPosY = m_player.getPosY() + j;
                        while (t < m_NPC.GetNPC())
                        {
                            if (m_NPC.npc_PosX[t] == checkPosX && m_NPC.npc_PosY[t] == checkPosY)
                            {
                                playerInRange[t] = true;
                            }
                            t++;
                        }
                    }
                }

                if (playerInRange[p] == false)
                {
                    bool moved = false;
                    int intentos = 0;
                    while (!moved && intentos < 10)
                    {
                        int newX = m_NPC.npc_PosX[p];
                        int newY = m_NPC.npc_PosY[p];
                        int randomMoviment = numRandom(1, 4);

                        switch (randomMoviment)
                        {
                        case 1: // Arriba
                            newX--;
                            break;
                        case 2: // Abajo
                            newX++;
                            break;
                        case 3: // Izquierda
                            newY--;
                            break;
                        case 4: // Derecha
                            newY++;
                            break;
                        }
                        int limiteX = m_map.getFilas() - 1;
                        int limiteY = m_map.getColumnas() - 1;
                        // Verifica que la posición nueva esté dentro del mapa
                        if (newX >= 0 && newX < limiteX && newY >= 0 && newY < limiteY)
                        {
                            // Verifica que la casilla esté vacía
                            if (m_map.m_Type[newX][newY] == objectType::DEFAULT)
                            {
                                // Libera la casilla anterior
                                m_map.m_Type[m_NPC.npc_PosX[p]][m_NPC.npc_PosY[p]] = objectType::DEFAULT;

                                // Actualiza posición
                                m_NPC.npc_PosX[p] = newX;
                                m_NPC.npc_PosY[p] = newY;

                                // Marca la casilla como NPC
                                m_map.m_Type[newX][newY] = objectType::NPC;

                                moved = true;
                            }
                        }
                        intentos++;
                    }
                }

            }
            else
            {
                do
                {
                    if (GetCurrentZone() == 0)
                    {
                        m_NPC.npc_Life[p] = m_NPC.GetLifeNpcSantos();
                        m_NPC.npc_PosX[p] = numRandom(1, m_map.getFilas() - 1);
                        m_NPC.npc_PosY[p] = numRandom(1, m_map.getLimitLosSantos() - 1);
                    }
                    else if (GetCurrentZone() == 1)
                    {
                        m_NPC.npc_Life[p] = m_NPC.GetLifeNpcSanFierro();
                        m_NPC.npc_PosX[p] = numRandom(1, m_map.getFilas() - 1);
                        m_NPC.npc_PosY[p] = numRandom(m_map.getLimitLosSantos() + 1, m_map.getLimitSanFierro() - 1);
                    }
                    else if (GetCurrentZone() == 2)
                    {
                        m_NPC.npc_Life[p] = m_NPC.GetLifeNpcLasVenturas();
                        m_NPC.npc_PosX[p] = numRandom(1, m_map.getFilas() - 1);
                        m_NPC.npc_PosY[p] = numRandom(m_map.getLimitSanFierro() + 1, m_map.getColumnas() - 1);
                    }
                } while (m_map.m_Type[m_NPC.npc_PosX[p]][m_NPC.npc_PosY[p]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio

                m_map.m_Type[m_NPC.npc_PosX[p]][m_NPC.npc_PosY[p]] = objectType::NPC;
                m_NPC.npc_Alive[p] = true;
                m_NPC.npc_Attacked[p] = false;
            }
        }
        
    
    
}
void Game::AttackNPC()
{
        for (int i = 0; i < m_NPC.GetNPC(); i++)
        {
            if (m_NPC.npc_Alive[i] == true)
            {
                if (m_NPC.npc_Attacked[i] == true)
                {
                    m_player.RecieveDamage(m_NPC.npc_Power[i]);
                }
            }
        }
		if(m_NPC.bsAttacked == true)
		{
			m_player.RecieveDamage(m_NPC.getBSPower());
		}
}
void Game::ResetGame()
{
	for (int i = 0; i < m_NPC.GetNPC(); i++)
	{
		m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::DEFAULT;
		m_NPC.npc_Alive[i] = false;
		m_NPC.npc_Attacked[i] = false;
	}
	m_map.m_Type[m_NPC.bs_PosX][m_NPC.bs_PosY] = objectType::DEFAULT;
	m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::DEFAULT;
	m_map.m_Type[40][m_map.getLimitLosSantos()] = objectType::PEAJE;
    m_map.m_Type[10][m_map.getLimitSanFierro()] = objectType::PEAJE;
    m_player.SetPos(m_fileRead.getFilas() - 1,m_fileRead.getLimitLosSantos() - 1);
    m_player.ResetLife();
    SetPlayer();
    CreateNPC();
	menuOption = -1;
    
}
Game::~Game()
{

}
