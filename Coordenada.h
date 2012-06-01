#ifndef _Coordenada
#define _Coordenada

#include <iostream>

using namespace std;

class Coordenada
{
  private:
    int x;
    int y;
   
  public:
    Coordenada(); // Constructor vacio
    Coordenada(int x, int y); // Constructor que recibe valores int (por ejemplo, 0 3)
    Coordenada(char fila, char columna); // Constructor que recibe valores char (por ejemplo, 5 b)
    Coordenada(const Coordenada &c) { x=c.x; y=c.y; }  // Constructor de copia. Ejemplo de declaracion inline 
    int getX() const; // Devuelve el valor de x
    int getY() const; // Devuelve el valor de y
    string getFormatoFichero() const; // Obtiene un string con los valores de la coordenada (por ejemplo, "b5")
    Coordenada diferencia(const Coordenada &c) const; // Calcula la diferencia entre la coordenada actual y la que se le pasa por parametro
    bool isError() const { return (x==-1 && y==-1); } // Devuelve true si se trata de una coordenada erronea

    static Coordenada coordenadaError; // Coordenada por defecto (-1,-1)
};

#endif
