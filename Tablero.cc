/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#include "Tablero.h"

Tablero::Tablero(){}

//LAS X seran las filas, y las Y las columnas, al contrario que en matemáticas, pero me guio según los métodos de coordenadas
void Tablero::inicializar()
{
		int x,y;

		//Recorremos el tablero de 7 a 0 (xs) y de 0 a 7 (ys)
		for (x=0;x<kTAM;x++)
		{
			for (y=0;y<kTAM;y++)
			{
				switch (x) //Dependiendo de la x en la que se encuentre, colocara las piezas correspondientes
				{
				  case 0:
				      piezas[x][y].setColor(NEGRO);
				      piezas[x][0].setTipo(TORRE);
				      piezas[x][1].setTipo(CABALLO);
				      piezas[x][2].setTipo(ALFIL);
				      piezas[x][3].setTipo(DAMA);
				      piezas[x][4].setTipo(REY);
				      piezas[x][5].setTipo(ALFIL);
				      piezas[x][6].setTipo(CABALLO);
				      piezas[x][7].setTipo(TORRE);
				      break;
				  case 1:
					  piezas[x][y].setTipo(PEON);
				      piezas[x][y].setColor(NEGRO);
				      break;
				  case 2:
				  case 3:
				  case 4:
				  case 5:
					  piezas[x][y].setVacia();
				      break;
				  case 6:
					  piezas[x][y].setTipo(PEON);
					  piezas[x][y].setColor(BLANCO);
					  break;
				  default:
				      piezas[x][y].setColor(BLANCO);
				      piezas[x][0].setTipo(TORRE);
				      piezas[x][1].setTipo(CABALLO);
				      piezas[x][2].setTipo(ALFIL);
				      piezas[x][3].setTipo(DAMA);
				      piezas[x][4].setTipo(REY);
				      piezas[x][5].setTipo(ALFIL);
				      piezas[x][6].setTipo(CABALLO);
				      piezas[x][7].setTipo(TORRE);
				      break;
				 }
			}
		}
}
void Tablero::mostrar(const Coordenada &ultimoMovimiento) const
{
	int x,y;

		cout << "-----------------" <<endl;
		for (x=0;x<kTAM;x++)
		{
			cout << 8-x << " ";
			for(y=0;y<kTAM;y++)
			{
			    cout << piezas[x][y].getSimbolo();
			    if (ultimoMovimiento.getX()==x && ultimoMovimiento.getY()==y) cout << "*";
			    else cout << " ";
	        	}
			cout << endl;
		}
		cout << "  a b c d e f g h" << endl;
}
Pieza Tablero::getPieza(const Coordenada &c) const
{
	return piezas[c.getX()][c.getY()];
}
Pieza Tablero::getPieza(int x, int y) const
{
	return piezas[x][y];
}
void Tablero::setPieza(const Coordenada &c, const Pieza &p)
{
	piezas[c.getX()][c.getY()]=p;
}
void Tablero::vaciarPieza(const Coordenada &c)
{
	piezas[c.getX()][c.getY()].setVacia();
}

