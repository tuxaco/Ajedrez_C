/*Alberto Castillo 53241547-C || Alberto Manuel Cervantes Bañón 74246650-M*/

#include "Partida.h"
#include <string.h>

Partida::Partida()
{
	numMovimientos=0;
	turno=BLANCO;
	tablero.inicializar();
}

void Partida::inicializar()
{
	numMovimientos=0;
	turno=BLANCO;
	tablero.inicializar();
	}
void Partida::jugar()
{
	Coordenada ultimoMovimiento;
	Movimiento mov;

	string orden="";


	  //Bucle que nos permite interactuar con el tablero
	    do{
	        if(numMovimientos!=0)
	        {
	            ultimoMovimiento=(movimientos[numMovimientos].getDestino());
	        }

	        tablero.mostrar(ultimoMovimiento);


	        cout << "Orden: ";
	        cin >> orden;

	        mov=Movimiento(orden);

	        if (orden=="h")
	        {
	            mostrarAyuda();
	        }
	        else if(orden=="q"){}
	        else if(orden=="g")
	        {
	            guardar();
	        }
	        else
	        {
	          if(mov.isError()!=1)
	          {
	        	if(moverPieza(mov))
	        	{//Despues de mover asignamos a ultimo movimiento destino
	        		numMovimientos++;
	        		movimientos[numMovimientos]=Movimiento(mov.getOrigen(),mov.getDestino());
	        		ultimoMovimiento=movimientos[numMovimientos].getDestino();
	        	}
	           }
			   else
			   {
					cout << kERROR2<<endl;
			   }
	        }
	    }while(orden!="q");

	}

void Partida::mostrarAyuda() const
{
	cout << "Ejemplo de movimientos: e2e4" << endl;
	cout << "Otras opciones:" <<endl;
	cout << "  h: Ayuda" <<endl;
	cout << "  g: Guardar partida" <<endl;
	cout << "  q: Salir de la partida"<<endl;
	}
bool Partida::moverPieza(const Movimiento &m)
{
	bool correcto=false;
		//cout<<m.getOrigen().getX()<<m.getOrigen().getY()<<m.getDestino().getX()<<m.getDestino().getY();
		if(movimientoEsCorrecto(m))
		{
			if (turno==BLANCO)
			{
				turno=NEGRO;
			}
			else
			{
				turno=BLANCO;
			}
			tablero.setPieza(m.getDestino(),tablero.getPieza(m.getOrigen()));
			tablero.vaciarPieza(m.getOrigen());
			correcto=true;
		}
		else
		{
			cout << kERROR3<<endl;
			correcto=false;
		}

	return correcto;
}
bool Partida::movimientoEsCorrecto(const Movimiento &m)
{
    bool correcto=false;

    if((tablero.getPieza(m.getOrigen()).getTipo()!=VACIA) && (tablero.getPieza(m.getOrigen()).getColor()==turno) &&
      (tablero.getPieza(m.getDestino()).getTipo()==VACIA || tablero.getPieza(m.getDestino()).getColor()!=turno))
    {
        if(comprobacionMovimientos(m))
        {
            correcto=true;
        }
        else
        {
            correcto=false;
        }
    }
    else
    {
        correcto=false;
    }
    return correcto;
}
bool Partida::comprobacionMovimientos(const Movimiento &m)
{
	bool correcto=false;

	Coordenada aux(m.getDestino().diferencia(m.getOrigen()));

	switch(tablero.getPieza(m.getOrigen()).getTipo()) //Dependiendo del "tipo" se comprueba si su movimiento es correcto
	{
		case PEON:correcto=comprobarPeon(aux,m);
				  break;
		case CABALLO:correcto=comprobarCaballo(aux);
				  break;
		case ALFIL:correcto=comprobarAlfil(aux, m);
				  break;
		case TORRE:correcto=comprobarTorre(aux, m);
				  break;
		case DAMA:correcto=comprobarDama(aux, m);
				  break;
		case REY:correcto=comprobarRey(aux);
				  break;
		default:correcto=false;
				  break;
	}
	return correcto;
}
bool Partida::comprobarPeon(Coordenada aux,const Movimiento &m)
{
	   bool correcto=false;

	    if(aux.getY() == 0) //Movida Vertical
	    {
	        if(abs(aux.getX()) == 1)//Si mueve una casilla
	        {
	            if(tablero.getPieza(m.getDestino()).getTipo()==VACIA && ((aux.getX()!=1 && tablero.getPieza(m.getOrigen()).getColor()==BLANCO) || (aux.getX()!=-1 && tablero.getPieza(m.getOrigen()).getColor()==NEGRO)))
	            {
	                correcto=true;
	            }
	            else
	            {
	                correcto=false;
	            }
	        }
	        else
	        {
	            //Si mueve dos casillas, comprobamos que salga desde la fila 1 si es blanco, o desde la fila 6 si es negro. Y que donde se mueva, sea una casilla vacia.
	            if(abs(aux.getX())==2 && ((m.getOrigen().getX()==6 && tablero.getPieza(m.getOrigen()).getColor()==BLANCO) || (m.getOrigen().getX()==1 && tablero.getPieza(m.getOrigen()).getColor()==NEGRO)) && tablero.getPieza(m.getDestino()).getTipo()==VACIA )
	            {
	                if(noHayPiezas(aux,m))
	                {
	                    correcto=true;
	                }
	                else
	                {
	                    correcto=false;
	                }
	            }
	            else
	            {
	                correcto=false;
	            }
	        }
	    }
	    else
	    {
	        //Parte que comprueba que le peón come correctamente, es decir en diagonal y a 1.
	        if((abs(aux.getY()) == 1) && ((tablero.getPieza(m.getOrigen()).getColor()==BLANCO && aux.getX()==-1) || (tablero.getPieza(m.getOrigen()).getColor()==NEGRO && aux.getX()==1)) && tablero.getPieza(m.getDestino()).getTipo()!=VACIA)
	        {
	            correcto = true;
	        }
	        else
	        {
	            correcto=false;
	        }
	    }

	    return correcto;
	}
bool Partida::comprobarCaballo(Coordenada aux)
{
	bool correcto=false;

	if(((abs(aux.getX()) == 2) && (abs(aux.getY()) == 1))||((abs(aux.getX()) == 1) && (abs(aux.getY()) == 2))) //Comprueba que se mueva 2 horizontal y un 1 vertical, o 1 horizontal y 2 vertical, es decir, una L
	{
			correcto=true;
	}

	return correcto;
}
bool Partida::comprobarAlfil(Coordenada aux,const Movimiento &m)
{
	bool correcto=false;

	    if(abs(aux.getX()) == abs(aux.getY())) //Comprueba que le valor de absoluto de x sea el de y, es decir que se mueva en diagonal
	    {
	        if(noHayPiezas(aux,m))
	        {
	            correcto=true;
	        }
	        else
	        {
	            correcto=false;
	        }
	    }
	    else
	    {
	        correcto=false;
	    }

	    return correcto;
	}
bool Partida::comprobarTorre(Coordenada aux,const Movimiento &m)
{
	bool correcto=false;

	if(aux.getX()==0 || aux.getY()==0)
	{
		if(noHayPiezas(aux,m))
		{
			correcto=true;
		}
		else
		{
			correcto=false;
		}
	}
	else
	{
		correcto=false;
	}


	return correcto;
}
bool Partida::comprobarDama(Coordenada aux,const Movimiento &m)
{
	bool correcto=false;

	    if(comprobarTorre(aux,m)||comprobarAlfil(aux,m))
	    {
	        if(noHayPiezas(aux,m))
	        {
	            correcto=true;
	        }
	        else
	        {
	            correcto=false;
	        }
	    }
	    else
	    {
	        correcto=false;
	    }


	    return correcto;
}
bool Partida::comprobarRey(Coordenada aux)
{
	bool correcto=false;

	if((abs(aux.getX())==0 && abs(aux.getY())==1)||(abs(aux.getX())==1 && abs(aux.getY())==0) ||((abs(aux.getX())==1) && (abs(aux.getY())==1)))
	{
			correcto=true;
	}

	return correcto;
}
bool Partida::noHayPiezas(Coordenada aux, const Movimiento &m)
{
	int i=0;
	Coordenada blancos;
	bool correcto=true;

	if(aux.getY()==0) //Movimiento Vertical
	{
		for(i=1;i<abs(aux.getX());i++)
		{
			if (aux.getX()<0) {blancos=Coordenada(m.getOrigen().getX()-i,m.getOrigen().getY());}
			else{blancos=Coordenada(m.getOrigen().getX()+i,m.getOrigen().getY());}

			if(tablero.getPieza(blancos.getX(),blancos.getY()).getTipo()!= VACIA)
			{
				 correcto=false;
			}
}
	}
	else if(aux.getX()==0) //Movimiento Horizontal
	{
		for(i=1;i<abs(aux.getY());i++)
		{
			if (aux.getY()<0) {blancos=Coordenada(m.getOrigen().getX(),m.getOrigen().getY()-i);}
			else{blancos=Coordenada(m.getOrigen().getX(),m.getOrigen().getY()+i);}

			if(tablero.getPieza(blancos.getX(),blancos.getY()).getTipo()!= VACIA)
			{
				correcto=false;
			}
		}

	}
	else if(abs(aux.getX()) == abs(aux.getY())) //Movimiento diagonal
	{
		for(i=1;i<abs(aux.getX());i++)
		{
			if (aux.getY()<0) {blancos=Coordenada(m.getOrigen().getX(),m.getOrigen().getY()-i);}
			else{blancos=Coordenada(m.getOrigen().getX(),m.getOrigen().getY()+i);}

			if (aux.getX()<0) {blancos=Coordenada(blancos.getX()-i,blancos.getY());}
			else{blancos=Coordenada(blancos.getX()+i,blancos.getY());}

			if(tablero.getPieza(blancos.getX(),blancos.getY()).getTipo()!=VACIA)
			{
				correcto=false;
			}
		}
	}

	return correcto;
}

//Función que guarda los movimientos correctos que llevamos hasta el momento de guardar la partida.
void Partida::guardar() const
{
  string guardar="";
  int i;

  cout << kFICHERO;
  cin >> guardar;

  ofstream f_texto;
  f_texto.open(guardar.c_str(),ios::out);

  if(f_texto.is_open())
  {
    for (i=1;i<=numMovimientos;i++)
    {
        f_texto << movimientos[i].getOrigen().getFormatoFichero()<<movimientos[i].getDestino().getFormatoFichero()<<" ";
    }
    f_texto.close();
  }
  else
  {
    cout << kERROR5;
  }

}
bool Partida::cargar()
{
  string cargar="";
  string fila="";
  unsigned int i=0;
  bool correcto=false;
  inicializar();

  cout << kFICHERO;
  cin >> cargar;

  ifstream f_texto;
  f_texto.open(cargar.c_str(),ios::in);
  if(f_texto.is_open()){
	do{
	  getline(f_texto,fila);
	  for (i=0; i<fila.length();i++)
	  {
	    if(fila[i]==' ' || fila.length()-1==i)
	    {
	      numMovimientos++;
	      movimientos[numMovimientos].setOrigen(Coordenada(fila[i-3],fila[i-4]));
	      movimientos[numMovimientos].setDestino(Coordenada(fila[i-1],fila[i-2]));
	      moverPieza(movimientos[numMovimientos]);
	    }


	  }
	}while(!f_texto.eof());
    f_texto.close();
    correcto=true;
  }
  else
  {
    cout << kERROR4;
  }

  return correcto;

}

void Partida::buscarApertura()
{
	    int indice=0;
	    unsigned int i=0;
	    inicializar();

	    Coordenada ultimoMovimiento;

		AperturaBinario apertura;

	 	indice=buscarBinario();

	    if(indice!=-1)
	    {
	        ifstream f_binario;
	        f_binario.open("aperturas.dat",ios::in | ios::binary);

	        if(f_binario.is_open())
	        {
	            f_binario.seekg((indice)*sizeof(apertura),ios::beg);
	            f_binario.read((char *)&apertura, sizeof(apertura));
	            cout<<apertura.nombre<<apertura.variacion<<endl;
	            cout<<apertura.movimientos<<endl;
	        }
	        else
	        {
	            cout<<kERROR4;
	        }
	        f_binario.close();


	        for(i=0; i<strlen(apertura.movimientos);i++)
	        {
	            if(apertura.movimientos[i]==' ' || strlen(apertura.movimientos)-1==i)
	            {
	                numMovimientos++;
	                movimientos[numMovimientos].setOrigen(Coordenada(apertura.movimientos[i-3],apertura.movimientos[i-4]));
	                movimientos[numMovimientos].setDestino(Coordenada(apertura.movimientos[i-1],apertura.movimientos[i-2]));

					if(moverPieza(movimientos[numMovimientos]))
					{
					  ultimoMovimiento=movimientos[numMovimientos].getDestino();
					}

				    if(strlen(apertura.movimientos)-1!=i)
	                {
	                    tablero.mostrar(ultimoMovimiento);
	                }

	            }


	        }
	        jugar();
	    }
	}

//Módulo que devuelve la apertura que deseamos utilizar.
int Partida::buscarBinario()
{
	string nombre=" ";
	string busqueda=" ";

	int i=0,j=0;

	int encontrado=0;
	int indice=0;
	int opcion=0;

	AperturaBinario apertura;
	int indices[3000];

	ifstream f_binario;
	f_binario.open("aperturas.dat",ios::in | ios::binary);

	if(f_binario.is_open())
	{
		cout<<"Busqueda: ";
		cin>>busqueda;

		f_binario.read((char *)&apertura, sizeof(apertura));
		while (!f_binario.eof())
		{
			  nombre=apertura.nombre;
			  encontrado=nombre.find(busqueda);

			  if(encontrado!=-1)
			  {
				indices[j]=i;
				cout << j+1<<" "<<nombre<<" "<<apertura.variacion<<endl;
				  j++;
			  }
			 i++;
			f_binario.read((char *)&apertura, sizeof(apertura));
		}
		indices[j]='\0';

		if(j!=0)//Contador de aperturas encontradas
		{
		   opcion=elegirApertura(j);
		   if (opcion!=-1)
		   {
			   indice=indices[opcion-1];
		   }
		   else
		   {
			   indice=-1;
		   }
		}
		else
		{
		   cout << kERROR7<<endl;
			indice=-1;
		}


	}
	else
	{
	  cout<<kERROR4;
	}
	f_binario.close();

	return indice;
}

//Módulo que nos permite elegir una de las apertura anteriormente buscadas
int Partida::elegirApertura(int j)
{
  int opcion=0;


  cout<<"Seleccionar apertura:";
  cin>>opcion;


  if(opcion<=0 || opcion>j)
  {
	cout<<kERROR6<<endl;
	opcion=-1;

  }

  return opcion;
}
