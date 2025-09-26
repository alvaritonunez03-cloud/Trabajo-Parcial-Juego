
#pragma once
#include "Pantalla.h"
#include "Personaje.h"
#include "Musica.h"

class Mundo {
private:
	Pantalla* pantalla;
	Personaje jugador;
	Pantalla mundo[3][3];
	int pantallaX, pantallaY;
public:
	Mundo();
	~Mundo();
	void mundo1();
};

Mundo::Mundo() {};
Mundo::~Mundo() {};
void Mundo::mundo1() {
	int tecla;
	bool p1, p2, p3, p4, mundo1 = true;
	p1 = true; p2 = false; p3 = false; p4 = false;

	Musica musica1("43. Castle Funk (DELTARUNE Chapter 34 Soundtrack) - Toby Fox.wav");
	musica1.reproducir(true);

	mundo[2][2].dibujarPantalla1();
	while (mundo1)
	{
		while (p1)
		{
			jugador.dibujar();
			if (_kbhit())
			{
				tecla = _getch();
				jugador.borrar();
				jugador.movimiento(tecla);
				jugador.dibujar();
			}
			pantalla->cambiarPantalla1(jugador.getX(), jugador.getY(), p1, p2, p3);
			_sleep(30);
		}

		if (p2) {
			jugador.borrar();
			jugador.setX(100);//Para posicionar al jugadro al otro lado
			jugador.setY(10);//Creo que es mejor hacer una clase en el jugador xd
		}
		if (p3) {
			jugador.borrar();
			jugador.setX(10);//Para posicionar al jugadro al otro lado
			jugador.setY(10);//Creo que es mejor hacer una clase en el jugador xd
		}

		while (p2)
		{
			jugador.dibujar();
			if (_kbhit())
			{
				tecla = _getch();
				jugador.borrar();
				jugador.movimiento(tecla);
				jugador.dibujar();
			}

			pantalla->cambiarPantalla21(jugador.getX(), jugador.getY(), p1, p2);
			_sleep(30);
		}

		if (p1) {
			jugador.borrar();
			jugador.setX(10);//Para posicionar al jugadro al otro lado
			jugador.setY(10);//Creo que es mejor hacer una clase en el jugador xd
		}


		while (p3)
		{
			jugador.dibujar();
			if (_kbhit())
			{
				tecla = _getch();
				jugador.borrar();
				jugador.movimiento(tecla);
				jugador.dibujar();
			}
		}

	}
}
