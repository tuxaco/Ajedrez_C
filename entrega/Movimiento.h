/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#ifndef _Movimiento
#define _Movimiento

#include <iostream>
#include "Coordenada.h"

using namespace std;

class Movimiento
{
private:
	Coordenada origen;
	Coordenada  destino;
public:

	Movimiento();
	Movimiento(string s);
	Movimiento(const Coordenada &origen, const Coordenada &destino);
	Movimiento(const Movimiento &m);
	void setOrigen(const Coordenada &origen);
	void setDestino(const Coordenada &destino);
	Coordenada getOrigen() const;
	Coordenada getDestino() const;
	bool isError() const;

	static Movimiento movimientoError;

};

#endif
