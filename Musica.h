#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")  //Liberia para el playsound

class Musica {
private:
	std::string archivo;
public:
	Musica(std::string);
	~Musica();
	void reproducir(bool);
	void detener();
};

Musica::Musica(std::string _archivo) {
	archivo = _archivo;
}
Musica::~Musica() {}
void Musica::reproducir(bool bucle) {
	PlaySoundA(archivo.c_str(), NULL, SND_FILENAME | SND_ASYNC | (bucle ? SND_LOOP : 0));
}
void Musica::detener() {
	PlaySoundA(NULL, NULL, 0);
}
