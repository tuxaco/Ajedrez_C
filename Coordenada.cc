#include "Coordenada.h"

Coordenada Coordenada::coordenadaError;

Coordenada::Coordenada()
{
  x=y=-1;
}

Coordenada::Coordenada(int x, int y)
{
 if (x>=0 && x<8 && y>=0 && y<8)
 {
    this->x=x;
    this->y=y;
 }
 else {
   *this=coordenadaError;
 }
}

Coordenada::Coordenada(char fila, char columna)
{
  if (fila>='1' && fila<='8' && columna>='a' && columna<='h')
  {
    y=columna-'a';
    x='8'-fila;
  }  
  else {
   *this=coordenadaError;
  }
}

int Coordenada::getX() const
{
  return x;
}

int Coordenada::getY() const
{
  return y;
}

Coordenada Coordenada::diferencia(const Coordenada &b) const
{
  Coordenada d;

  d.x=x-b.x;
  d.y=y-b.y;

  return d;
}

string Coordenada::getFormatoFichero() const
{
  string salida;

  salida+= (char)('a'+y);
  salida+= (char)(8-x+'0');

  return salida;
}
