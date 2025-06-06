#include "Util.h"

Player::Player()
{
	//m_PosX = numRandom(1, m_map.getFilas() - 1);
	//m_PosY = numRandom(1, m_map.getLimitLosSantos() - 1);
	cjDead = false;
}
void Player::SetPos(int posX, int posY)
{
	m_PosX = numRandom(1, posX);
	m_PosY = numRandom(1,posY);
}
void Player::StatsCJ(int m_life, int m_power)
{
	life = m_life;
	power = m_power;
}
void Player::moveForward() 
{
	m_PosX--;
	
}
void Player::moveLeft()
{
	m_PosY--;
	
}
void Player::moveBack()
{
	m_PosX++;
	
}
void Player::moveRight()
{ 
	m_PosY++;
	
}
void Player::RecieveDamage(int damage)
{
	life -= damage;
	if (life < 0)
	{
		cjDead = true;// Asegurarse de que la vida no sea negativa
	}
}
