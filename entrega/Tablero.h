/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#ifndef _Tablero
#define _Tablero

#include <iostream>
#include "Pieza.h"
#include "Coordenada.h"

using namespace std;

const int kTAM=8;

class Tablero
{
private:
	Pieza piezas[kTAM][kTAM];

public:
	Tablero();
	void inicializar();
	void mostrar(const Coordenada &ultimoMovimiento) const;
	Pieza getPieza(const Coordenada &c) const;
	Pieza getPieza(int x, int y) const;
	void setPieza(const Coordenada &c, const Pieza &p);
	void vaciarPieza(const Coordenada &c);
};


#endif
