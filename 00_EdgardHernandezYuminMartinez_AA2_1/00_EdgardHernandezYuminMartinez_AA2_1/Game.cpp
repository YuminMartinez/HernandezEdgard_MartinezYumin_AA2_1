#include "Game.h"
#include <Windows.h> 


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
      // se mueve hacia delante
    if (m_player.getPosY() < m_map.getLimitLosSantos())
    {
		MapPos = 0; // Los Santos
    }
    else if (m_player.getPosY() >= m_map.getLimitLosSantos() && m_player.getPosY() < m_map.getLimitSanFierro())
    {
		MapPos = 1; // San Fierro
    }
    else if (m_player.getPosY() >= m_map.getLimitSanFierro())
    {
		MapPos = 2; // Las Venturas
    }
    
        if (GetAsyncKeyState(VK_LEFT) & 0x8000 && y > 0)
        {
            if (m_map.m_Type[x][y - 1] == objectType::DEFAULT || m_map.m_Type[x][y - 1] == objectType::PEAJE)
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
                if (MapPos == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySantos()));
				}
				else if (MapPos == 1)
				{
					m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySanFierro()));
				}
                else if (MapPos == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneyLasVenturas()));
                }
            }
        }// se mueve hacia izquierda
        else if (GetAsyncKeyState(VK_UP) & 0x8000 && y > 0)
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
                if (MapPos == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySantos()));
                }
                else if (MapPos == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySanFierro()));
                }
                else if (MapPos == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneyLasVenturas()));
                }
            }
        }// se mueve hacia atras
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && x < m_map.getFilas() - 1)
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
                if (MapPos == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySantos()));
                }
                else if (MapPos == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySanFierro()));
                }
                else if (MapPos == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneyLasVenturas()));
                }

            }
        }// se mueve hacia derecha
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && y < m_map.getColumnas() - 1)
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
                if (MapPos == 0)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySantos()));
                }
                else if (MapPos == 1)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneySanFierro()));
                }
                else if (MapPos == 2)
                {
                    m_player.addMoney(numRandom(1, m_NPC.getMaxMoneyLasVenturas()));
                }
            }

        }
        else
        {
            m_player.SetPosX(x);
            m_player.setPosY(y);
        }

        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            // Coordenadas de las 4 casillas adyacentes (arriba, abajo, izquierda, derecha)
            int adjacent[4][2] = { {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1} };
            // Buscar NPCs adyacentes
            for (int i = 0; i < 4; ++i)
            {
                int targetX = adjacent[i][0];
                int targetY = adjacent[i][1];


                // Verificar si hay un NPC en la posición de ataque
                if (targetX >= 0 && targetX < m_map.getFilas() && targetY >= 0 && targetY < m_map.getColumnas() && (m_map.m_Type[targetX][targetY] == objectType::NPC|| m_map.m_Type[targetX][targetY] == objectType::BIGSMOKE))
                {
                    // 1. Eliminar el NPC del array
                    for (int i = 0; i < m_NPC.getNPC(); i++)
                    {
                        if (m_NPC.npc_PosX[i] == targetX && m_NPC.npc_PosY[i] == targetY)
                        {
							m_NPC.npcDamage(m_player.getPower(), i); 
                            if (m_NPC.npc_Alive[i] == false)
                            {
                                m_map.m_Type[targetX][targetY] = objectType::MONEY;
                            }
                            break;
                        }
                    }
                    if (m_map.m_Type[targetX][targetY] == objectType::BIGSMOKE)
                    {
						m_NPC.BsDamage(m_player.getPower());
						
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
                // Marcar al jugador con un símbolo especial (@)
                
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
                            std::cout << " "; 
                            break;
                        default: 
                            std::cout << "?";
                            break;
                    }
                
            }
        }
        std::cout << '\n';  // Nueva línea por cada fila del mapa
    }

    // Imprimir información de depuración
    std::cout << "\nJugador: (" << m_player.getPosX() << ", " << m_player.getPosY() << ")";
    std::cout << "\nVista: " << m_player.getPlayerViewWidth() << "x" << m_player.getPlayerViewHeight();
    std::cout << "\nMapa: " << m_map.getColumnas() << "x" << m_map.getFilas();
    std::cout << "\nDinero: " << m_player.getMoney() << "$";
	std::cout << "\nVidaCJ: " << m_player.getLife() << std::endl;
	
    
    
    /*for (int i = 0; i < m_map.getFilas(); ++i) {
        for (int j = 0; j < m_map.getColumnas(); ++j) {
            switch (m_map.m_Type[i][j]) {
            case objectType::LIMIT: std::cout << "X"; break;
            case objectType::PLAYER_UP: std::cout << "^"; break;
            case objectType::PLAYER_DOWN: std::cout << "v"; break;
            case objectType::PLAYER_LEFT: std::cout << "<"; break;
            case objectType::PLAYER_RIGHT: std::cout << ">"; break;
            case objectType::NPC: std::cout << "P"; break;
            case objectType::MONEY: std::cout << "$"; break;
            case objectType::CAR: std::cout << "C"; break;
			case objectType::BIGSMOKE: std::cout << "B"; break;
            case objectType::DEFAULT: std::cout << " "; break;
            case objectType::PEAJE: std::cout << " "; break;
            default: std::cout << "?"; break;
            }
        }
        std::cout << '\n';
    }*/
    

}

void Game::SetPlayer() 
{
   
    m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::PLAYER_UP;
}
void Game::CreateNPC()
{
    for (int i = 0; i < m_NPC.getNpcLosSantos(); i++)
    {
        do 
        {
            m_NPC.npc_PosX[i] = numRandom(1, m_map.getFilas() - 1);
            m_NPC.npc_PosY[i] = numRandom(1, m_map.getLimitLosSantos() - 1);
        } while (m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio

        m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::NPC;
        m_NPC.npc_Alive[i] = true;
		m_NPC.npc_Power[i] = m_NPC.getPowerNpcSantos();
		m_NPC.npc_Life[i] = m_NPC.getLifeNpcSantos();
		int Random = numRandom(0, 2);
        if (Random == 1)
        {
			m_NPC.npc_neutral[i] = true; 
		}
        else
        {
            m_NPC.npc_neutral[i] = false;
        }
		std::cout << "NPC " << i << " creado en (" << m_NPC.npc_PosX[i] << ", " << m_NPC.npc_PosY[i] << ")" << " Vida: " << m_NPC.npc_Life[i] << " Poder: " << m_NPC.npc_Power[i]<< std::endl;
    }
    for (int i = m_NPC.getNpcLosSantos(); i < (m_NPC.getNpcLosSantos() + m_NPC.getNpcSanFierro()); i++)
    {
        do
        {
            m_NPC.npc_PosX[i] = numRandom(1, m_map.getFilas() - 1);
            m_NPC.npc_PosY[i] = numRandom(m_map.getLimitLosSantos()+1, m_map.getLimitSanFierro() - 1);
        } while (m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio

        m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::NPC;
        m_NPC.npc_Alive[i] = true;
        m_NPC.npc_Power[i] = m_NPC.getPowerNpcSanFierro();
        m_NPC.npc_Life[i] = m_NPC.getLifeNpcSanFierro();
        int Random = numRandom(0, 2);
        if (Random == 1)
        {
            m_NPC.npc_neutral[i] = true;
        }
        else
        {
            m_NPC.npc_neutral[i] = false;
        }
        std::cout << "NPC " << i << " creado en (" << m_NPC.npc_PosX[i] << ", " << m_NPC.npc_PosY[i] << ")" << " Vida: " << m_NPC.npc_Life[i] << " Poder: " << m_NPC.npc_Power[i] << std::endl;
    }
    for (int i = m_NPC.getNpcLosSantos() + m_NPC.getNpcSanFierro(); i < (m_NPC.getNpcLosSantos() + m_NPC.getNpcSanFierro() + m_NPC.getNpcLasVenturas()); i++)
    {
		do
		{
			m_NPC.npc_PosX[i] = numRandom(1, m_map.getFilas() - 1);
			m_NPC.npc_PosY[i] = numRandom(m_map.getLimitSanFierro() + 1, m_map.getColumnas() - 1);
		} while (m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] != objectType::DEFAULT);  // Asegura que solo spawnean en un lugar donde este vacio
		m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::NPC;
		m_NPC.npc_Alive[i] = true;
        m_NPC.npc_Power[i] = m_NPC.getPowerNpcLasVenturas();
        m_NPC.npc_Life[i] = m_NPC.getLifeNpcLasVenturas();
        int Random = numRandom(0, 2);
        if (Random == 1)
        {
            m_NPC.npc_neutral[i] = true;
        }
        else
        {
            m_NPC.npc_neutral[i] = false;
        }
        std::cout << "NPC " << i << " creado en (" << m_NPC.npc_PosX[i] << ", " << m_NPC.npc_PosY[i] << ")" << " Vida: " << m_NPC.npc_Life[i] << " Poder: " << m_NPC.npc_Power[i] << std::endl;
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
        for (int p = 0; p < m_NPC.getNPC(); p++)
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
                        while (t < m_NPC.getNPC())
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
                    if (MapPos == 0)
                    {
                        m_NPC.npc_Life[p] = m_NPC.getLifeNpcSantos();
                        m_NPC.npc_PosX[p] = numRandom(1, m_map.getFilas() - 1);
                        m_NPC.npc_PosY[p] = numRandom(1, m_map.getLimitLosSantos() - 1);
                    }
                    else if (MapPos == 1)
                    {
                        m_NPC.npc_Life[p] = m_NPC.getLifeNpcSanFierro();
                        m_NPC.npc_PosX[p] = numRandom(1, m_map.getFilas() - 1);
                        m_NPC.npc_PosY[p] = numRandom(m_map.getLimitLosSantos() + 1, m_map.getLimitSanFierro() - 1);
                    }
                    else if (MapPos == 2)
                    {
                        m_NPC.npc_Life[p] = m_NPC.getLifeNpcLasVenturas();
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
        for (int i = 0; i < m_NPC.getNPC(); i++)
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
	for (int i = 0; i < m_NPC.getNPC(); i++)
	{
		m_map.m_Type[m_NPC.npc_PosX[i]][m_NPC.npc_PosY[i]] = objectType::DEFAULT;
		m_NPC.npc_Alive[i] = false;
		m_NPC.npc_Attacked[i] = false;
	}
	m_map.m_Type[m_NPC.bs_PosX][m_NPC.bs_PosY] = objectType::DEFAULT;
	m_map.m_Type[m_player.getPosX()][m_player.getPosY()] = objectType::DEFAULT;
    m_player.SetPos(m_fileRead.getFilas() - 1, m_fileRead.getLimitLosSantos() - 1);
    m_player.ResetLife();
    SetPlayer();
    CreateNPC();
    
    startGame = false;
	
}
Game::~Game()
{

}
