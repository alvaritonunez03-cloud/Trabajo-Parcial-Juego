#pragma once
#include <iostream>
#include <Windows.h>

#define BLANCO 15
#define AZUL 1

class Personaje
{
private:
	int x, y, dx, dy;
public:
	Personaje();
	~Personaje();
	void movimiento(int tecla);
	void dibujar();
	void borrar();
	void setX(int _x);
	void setY(int y);
	int getX();
	int getY();
};

Personaje::Personaje() {
	x = 60;
	y = 15; 
	dx = 1;
	dy = 1;
}
Personaje::~Personaje() {}
int Personaje::getX() { return x; }
int Personaje::getY() { return y; }
void Personaje::setX(int _x) { x = _x; }
void Personaje::setY(int _y) { y = _y; }
void Personaje::movimiento(int tecla) {
	if (tecla == 0 || tecla == 224) {
		tecla = _getch();

		switch (tecla)
		{
		case 72: y -= dy; break; // arriba
		case 80: y += dy; break; // abajo
		case 75: x -= dx; break; // izquierda
		case 77: x += dx; break; // derecha

		default:
			break;
		}
	}

	if (x > 113) x -= dx;
	if (x < 9) x += dx;
	if (y > 25) y -= dy;
	if (y < 3) y += dy;
}
void Personaje::dibujar() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	char s219 = 219;
	//Pirmera fila
	System::Console::SetCursorPosition(x, y);
	SetConsoleTextAttribute(color, BLANCO);
	std::cout << s219;

	System::Console::SetCursorPosition(x+1, y);
	SetConsoleTextAttribute(color, BLANCO);
	std::cout << s219;
	//Segunda fila
	System::Console::SetCursorPosition(x - 1, y + 1);
	SetConsoleTextAttribute(color, BLANCO);
	std::cout << s219;

	System::Console::SetCursorPosition(x, y + 1);
	SetConsoleTextAttribute(color, BLANCO);
	std::cout << s219;

	System::Console::SetCursorPosition(x + 1, y+1);
	SetConsoleTextAttribute(color, AZUL);
	std::cout << s219;
	//Tercera fila
	for (int i = x-3; i < x+2; i++)
	{
		System::Console::SetCursorPosition(i, y + 2);
		SetConsoleTextAttribute(color,BLANCO);
		std::cout << s219;
	}
}
void Personaje::borrar(){
	char s219 = 219;
	//Pirmera fila
	System::Console::SetCursorPosition(x, y);
	std::cout << " ";

	System::Console::SetCursorPosition(x + 1, y);
	std::cout << " ";
	//Segunda fila
	System::Console::SetCursorPosition(x - 1, y + 1);
	std::cout << " ";

	System::Console::SetCursorPosition(x, y + 1);
	std::cout << " ";

	System::Console::SetCursorPosition(x + 1, y + 1);
	std::cout << " ";
	//Tercera fila
	for (int i = x - 3; i < x + 2; i++)
	{
		System::Console::SetCursorPosition(i, y + 2);
		std::cout << " ";
	}
}
