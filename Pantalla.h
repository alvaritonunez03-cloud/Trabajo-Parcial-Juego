#pragma once
#include <iostream>
#include <Windows.h>

#define PURPURA 5
#define AZUL 1
#define VERDE 2

class Pantalla {
public:
	Pantalla();
	~Pantalla();
	void dibujarPantalla1();
	void dibujarPantalla2();
	void cambiarPantalla(int, int, bool&, bool&);
};
Pantalla::Pantalla() {};
Pantalla::~Pantalla() {};
void Pantalla::dibujarPantalla1() {

	char s219 = 219;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	//Parte frontal del mapa
	for (int i = 5; i < 115; i++)
	{
		System::Console::SetCursorPosition(i,2);
		SetConsoleTextAttribute(color, PURPURA);
		std::cout << s219;
	}
	//Parte baja del mapa
	for (int i = 5; i < 115; i++)
	{
		System::Console::SetCursorPosition(i, 28);
		SetConsoleTextAttribute(color, PURPURA);
		std::cout << s219;
	}
	//Parte izquierda del mapa
	for (int i = 2; i < 28; i++)
	{
		System::Console::SetCursorPosition(5, i);
		SetConsoleTextAttribute(color, PURPURA);
		std::cout << s219;
	}
	//Parte derecha del mapa
	for (int i = 2; i < 29; i++)
	{
		System::Console::SetCursorPosition(115, i);
		SetConsoleTextAttribute(color, PURPURA);
		std::cout << s219;
	}
}
void Pantalla::dibujarPantalla2() {
	char s219 = 219;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	//Parte frontal del mapa
	for (int i = 5; i < 115; i++)
	{
		System::Console::SetCursorPosition(i, 2);
		SetConsoleTextAttribute(color, AZUL);
		std::cout << s219;
	}
	//Parte baja del mapa
	for (int i = 5; i < 115; i++)
	{
		System::Console::SetCursorPosition(i, 28);
		SetConsoleTextAttribute(color, AZUL);
		std::cout << s219;
	}
	//Parte izquierda del mapa
	for (int i = 2; i < 28; i++)
	{
		System::Console::SetCursorPosition(5, i);
		SetConsoleTextAttribute(color, AZUL);
		std::cout << s219;
	}
	//Parte derecha del mapa
	for (int i = 2; i < 29; i++)
	{
		System::Console::SetCursorPosition(115, i);
		SetConsoleTextAttribute(color, AZUL);
		std::cout << s219;
	}

	System::Console::SetCursorPosition(40,10);
	SetConsoleTextAttribute(color, VERDE);
	std::cout << s219;

	System::Console::SetCursorPosition(20, 5);
	SetConsoleTextAttribute(color, VERDE);
	std::cout << s219;

	System::Console::SetCursorPosition(60, 25);
	SetConsoleTextAttribute(color, VERDE);
	std::cout << s219;

}
void Pantalla::cambiarPantalla(int x, int y, bool& p1, bool& p2) {
	if (x > 7 && x < 10 && y < 4) {//Ese rango de x es exacto lo que queremos
		dibujarPantalla2();
		p1 = false;
		p2 = true;
	}
}
