#pragma once
class Car
{
private:
	// Coches en cada ciudad
	int NumCarSantos = 3;
	int NumCarSanFierro = 3;
	int NumCarLasVenturas = 3;
public:

	int GetNumCarSanFierro() const {
		return NumCarSanFierro;
	}
	int GetNumCarSantos() const {
		return NumCarSantos;
	}

	int GetNumCarLasVenturas() const {
		return NumCarLasVenturas;
	}

};



