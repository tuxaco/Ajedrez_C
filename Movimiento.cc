/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/
#include "Movimiento.h"


Movimiento Movimiento::movimientoError;

Movimiento::Movimiento(){}
Movimiento::Movimiento(string s)
{
	if (s.length()==4)
	{
		origen=Coordenada(s[1],s[0]);
		destino=Coordenada(s[3],s[2]);
	}
	else
	{
	 *this=movimientoError;
	}

}
Movimiento::Movimiento(const Coordenada &origen, const Coordenada &destino)
{
	this->origen=origen;
	this->destino=destino;
}

Movimiento::Movimiento(const Movimiento &m)
{
	origen=m.origen;
	destino=m.destino;
}

void Movimiento::setOrigen(const Coordenada &origen)
{
	this->origen=origen;
	}
void Movimiento::setDestino(const Coordenada &destino)
{
	this->destino=destino;
	}
Coordenada Movimiento::getOrigen() const
{
	return origen;
	}

Coordenada Movimiento::getDestino() const
{
	return destino;
	}
bool Movimiento::isError() const
{
	bool error=false;
	if(origen.isError() || destino.isError())
	{
		error=true;
	}
	return error;

}
