/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#ifndef _Partida
#define _Partida

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Movimiento.h"
#include "Tablero.h"

using namespace std;

const string kFICHERO="Nombre fichero: ";

const string kERROR1="Opcion incorrecta";
const string kERROR2="Error: Orden incorrecta (h para ayuda)";
const string kERROR3="Error: Movimiento ilegal";
const string kERROR4="Error de apertura del fichero";
const string kERROR5="Error de escritura";
const string kERROR6="Error: numero de apertura incorrecto";
const string kERROR7="Sin resultados";

typedef struct {
	char nombre[80];
	char variacion[100];
	char movimientos[200];
}AperturaBinario;

class Partida
{
private:
	colorPieza turno;
	Tablero tablero;
	Movimiento movimientos[1000];
	//Métodos y atributos añadidos
	int numMovimientos;
	bool movimientoEsCorrecto(const Movimiento &m);
	bool comprobacionMovimientos(const Movimiento &m);
	bool comprobarPeon(Coordenada aux,const Movimiento &m);
	bool comprobarCaballo(Coordenada aux);
	bool comprobarAlfil(Coordenada aux,const Movimiento &m);
	bool comprobarTorre(Coordenada aux,const Movimiento &m);
	bool comprobarDama(Coordenada aux,const Movimiento &m);
	bool comprobarRey(Coordenada aux);
	bool noHayPiezas(Coordenada aux, const Movimiento &m);
	int buscarBinario();
	int elegirApertura(int j);

public:
	Partida();
	void inicializar();
	void jugar();
	void buscarApertura();
	void mostrarAyuda() const;
	bool moverPieza(const Movimiento &m);
	void guardar() const;
	bool cargar();


};


#endif
