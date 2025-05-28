#pragma once
class Car
{
private: 
	bool isParked = true;
	int posX;
	int PosY;

public :
	// Getters
	int getPosX() const 
	{
		return posX;
	}
	int getPosY() const 
	{
		return PosY;
	}
	bool getIsParked() const 
	{ 
		return isParked;
	}

	// Interact cj
	void enterCar() { isParked = false; }  // CJ up
	void exitCar() { isParked = true; }    // CJ down


};



