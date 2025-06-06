#pragma once
class Car
{
private:
	// Coches en cada ciudad
	int numCarSantos = 3;
	int numCarSanFierro = 3;
	int numCarLasVenturas = 3;
public:

	int GetNumCarSanFierro() const 
	{
		return numCarSanFierro;
	}
	int GetNumCarSantos() const 
	{
		return numCarSantos;
	}

	int GetNumCarLasVenturas() const
	{
		return numCarLasVenturas;
	}

};



