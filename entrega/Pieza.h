/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#ifndef _Pieza
#define _Pieza

#include <iostream>

using namespace std;

const string kVACIA=".";
const string kREYB="\u2654";
const string kDAMAB="\u2655";
const string kTORREB="\u2656";
const string kCABALLOB="\u2658";
const string kALFILB="\u2657";
const string kPEONB="\u2659";

const string kREYN="\u265A";
const string kDAMAN="\u265B";
const string kTORREN="\u265C";
const string kCABALLON="\u265E";
const string kALFILN="\u265D";
const string kPEONN="\u265F";

enum tipoPieza {
	VACIA, PEON, CABALLO, ALFIL, TORRE, DAMA, REY
};

enum colorPieza {
	BLANCO, NEGRO
};

class Pieza
{
private:
	tipoPieza tipo;
	colorPieza color;

public:
	Pieza(tipoPieza t=VACIA, colorPieza c=BLANCO):tipo(t),color(c){};
	tipoPieza getTipo() const;
	colorPieza getColor() const;
	void setTipo(tipoPieza tipo);
	void setColor(colorPieza color);
	bool isVacia() const;
	void setVacia();
	string getSimbolo() const;
};

#endif
