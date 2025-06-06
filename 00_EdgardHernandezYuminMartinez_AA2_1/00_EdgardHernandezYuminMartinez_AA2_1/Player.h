#pragma once
#include "Util.h"
class Player
{
private:
	int m_PosX;
	int m_PosY;
	int money = 0;
	int playerView_Width = 11;
	int playerView_Heigh = 11;
	int life;
	int power;
	bool cjDead = false; 
public:
	Player();
	
	
	// Getters
	int getPosX() const 
	{ 
		return m_PosX; 
	}
	int getPosY() const 
	{
		return m_PosY;
	}
	int getMoney() const
	{
		return money; 
	}
	int getPlayerViewWidth() const
	{ 
		return playerView_Width; 
	}
	int getPlayerViewHeight() const
	{
		return  playerView_Heigh;
	}
	int getLife() const
	{
		return life;
	}
	int getPower() const
	{
		return power;
	}
	bool GetCJDead() const
	{
		return cjDead;
	}
	void StatsCJ(int, int);
	//Setterss
	void addMoney(int amount) {
		if (amount > 0)
		{
			money += amount;
		}
	}
	
	void SetPosX(int positionX)
	{
		m_PosX = positionX;
	}
	void setPosY(int positionY)
	{ 
		m_PosY = positionY;
	}

	void ResetLife()
	{
		life = 100; // Valor inicial de vida
	}
	void moveForward();
	void moveLeft();
	void moveBack();
	void moveRight();
	void SetPos(int, int);
	void RecieveDamage(int);
	
};
