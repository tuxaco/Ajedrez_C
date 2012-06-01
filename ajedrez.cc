#include <iostream>
#include "Partida.h"

using namespace std;

const string kERROROPC="Opcion incorrecta";

void mostrarMenu()
{
  cout << "--------------------------------" << endl;
  cout << "---- Ajedrez Programacion 2 ----" << endl;
  cout << "--------------------------------" << endl;
  cout << "1- Comenzar partida" << endl;
  cout << "2- Cargar partida" << endl;
  cout << "3- Buscar apertura" << endl;
  cout << "q- Salir" << endl;
  cout << "Opcion : ";
}

int main()
{
  char opcion;

  do {
    mostrarMenu();
    cin >> opcion;
    cin.get();
    switch (opcion)
    {
      case '1':
              {
            	  Partida p;
            	  p.jugar();
              }
          break;
	  case '2':
			{
				Partida p;
				if (p.cargar())
					p.jugar();
				}
		   break;
	  case '3':
		    {
			    Partida p;
				p.buscarApertura();
			}
				break;
      case 'q': 
          break;
      default:
          cout << kERROROPC << endl;
          break;
    }
  } while (opcion!='q');
}
