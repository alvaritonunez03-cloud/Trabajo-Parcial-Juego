#pragma once
#include "Pantalla.h"
#include "Personaje.h"

class Mundo {
private:
	Pantalla* pantalla;
	Personaje jugador;
public:
	Mundo();
	~Mundo();
	void mundo1();
};

Mundo::Mundo() {};
Mundo::~Mundo() {};
void Mundo::mundo1() {
	int tecla;
	bool p1, p2, p3, p4;
	p1 = true; p2 = false; p3 = false; p4 = false;
	while (p1)
	{
	pantalla->dibujarPantalla1();
	jugador.dibujar();
		if (_kbhit())
		{
			tecla = _getch();
			jugador.borrar();
			jugador.movimiento(tecla);
			jugador.dibujar();
		}
		pantalla->cambiarPantalla(jugador.getX(),jugador.getY(),p1,p2);
		_sleep(100);
	}
	jugador.borrar();
	jugador.setX(100);//Para posicionar al jugadro al otro lado
	jugador.setY(10);//Creo que es mejor hacer una clase en el jugador xd
	while (p2)
	{
		pantalla->dibujarPantalla2();

		jugador.dibujar();
		if (_kbhit())
		{
			tecla = _getch();
			jugador.borrar();
			jugador.movimiento(tecla);
			jugador.dibujar();
		}

		_sleep(100);
	}
	
}
