
all: ajedrez

OBJS=Coordenada.o Movimiento.o Pieza.o Tablero.o Partida.o

ajedrez: $(OBJS) ajedrez.o
	g++ -o ajedrez $(OBJS) ajedrez.o
	
ajedrez.o: ajedrez.cc Partida.h
	g++ -c -g -Wall ajedrez.cc
	
Coordenada.o : Coordenada.h Coordenada.cc
	g++ -c -g -Wall Coordenada.cc

Movimiento.o : Movimiento.h Movimiento.cc
	g++ -c -g -Wall Movimiento.cc

Pieza.o : Pieza.h Pieza.cc
	g++ -c -g -Wall Pieza.cc

Tablero.o : Tablero.h Tablero.cc
	g++ -c -g -Wall Tablero.cc

Partida.o : Partida.h Partida.cc
	g++ -c -g -Wall Partida.cc


