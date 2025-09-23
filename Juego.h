#pragma once
#include <conio.h>
#include "Mundos.h"
class Juego
{
private:
	std::string nombre;
	Mundo mundos;
public:
	Juego();
	~Juego();
	int menu();
	void iniciarjuego();
	void instrucciones();
	void creditos();
	void mensajeLento(std::string, int);
};

Juego::Juego()
{
}
Juego::~Juego()
{
}
int Juego::menu()  {
	int tecla;
	int aux = 0;
	std::string opciones[4] = { "Jugar", "Instrucciones", "Creditos", "Salir" };
	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			System::Console::SetCursorPosition(50, 20+i);
			if (aux == i) std::cout << "> " << opciones[i] << std::endl;
			else std::cout << "  " << opciones[i] << std::endl;
		}
		tecla = _getch();
		if (tecla == 0 || tecla == 224) {
			tecla = _getch();
			switch (tecla)
			{
			case 72:
				system("cls");
				aux--;
				if (aux < 0) aux = 3;
				break;
			case 80:
				system("cls");
				aux++;
				if (aux > 3) aux = 0;
				break;
			default:
				break;
			}
			
		}
		else if(tecla == 13)//Enter
		{
			if (aux == 0) {
				return 1;//jugar
			}
			if (aux == 1) {
				return 2;//instrucciones
			}
			if (aux == 2) {
				return 3;//creditos
			}
			if (aux == 3) {
				return 0;//salir
			}
		}
	}
}
void Juego::iniciarjuego() {
	int tecla;

	system("cls");
	std::string mensaje1 = "Cual es tu nombre?: ";
	System::Console::SetCursorPosition(50, 10);
	mensajeLento(mensaje1, 60);
	std::cin >> nombre;

	system("cls");
	std::string mensaje2 = " estas por cometer el peor error de tu vida...";
	std::string mensaje3 = "Aun estas a tiempo de cambiar tu destino";
	std::string mensaje4 = "Mira tu mundo...";
	System::Console::SetCursorPosition(50,5);
	mensajeLento(mensaje2, 60);
	System::Console::SetCursorPosition(50, 7);
	mensajeLento(mensaje3, 60);
	System::Console::SetCursorPosition(50, 10);
	mensajeLento(mensaje4, 60);

	system("cls");
	Mundo mundos;

	mundos.mundo1();

};
void Juego::instrucciones() {};
void Juego::creditos() {};
void Juego::mensajeLento(std::string mensaje, int velocidad) {
	for (char c : mensaje) {
		std::cout << c << std::flush;
		Sleep(velocidad);
	}
}
