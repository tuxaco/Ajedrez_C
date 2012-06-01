/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#include "Pieza.h"

tipoPieza Pieza::getTipo() const
{
	return tipo;
}
colorPieza Pieza::getColor() const
{
	return color;
}
void Pieza::setTipo(tipoPieza tipo)
{
	this->tipo=tipo;
}
void Pieza::setColor(colorPieza color)
{
	this->color=color;
}
bool Pieza::isVacia() const
{
	bool vacia=false;
	if(tipo==VACIA){vacia=true;}
	return vacia;
}
void Pieza::setVacia()
{
	tipo=VACIA;
	color=BLANCO;
}
string Pieza::getSimbolo() const
{
	string codigo=" ";

	if (isVacia())
	{
	    codigo=kVACIA;
	}
	else
	{
	  if (color==BLANCO)
	  {
	      if (tipo==REY) codigo=kREYB;
	      else if (tipo==DAMA) codigo=kDAMAB;
	      else if (tipo==TORRE) codigo=kTORREB;
	      else if (tipo==ALFIL) codigo=kALFILB;
	      else if (tipo==CABALLO) codigo=kCABALLOB;
	      else codigo=kPEONB;
	   }
	   else
	   {
	      if (tipo==REY) codigo=kREYN;
	      else if (tipo==DAMA) codigo=kDAMAN;
	      else if (tipo==TORRE) codigo=kTORREN;
	      else if (tipo==ALFIL) codigo=kALFILN;
	      else if (tipo==CABALLO) codigo=kCABALLON;
	      else codigo=kPEONN;
	    }
	 }

	 return codigo;
}




