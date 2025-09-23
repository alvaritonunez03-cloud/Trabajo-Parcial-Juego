#include "pch.h"
#include "Juego.h"

int main()
{
    System::Console::CursorVisible = false;
    Juego obj;
    int opcion;
    //Entiendo que la pantalla es de 120 a 30 o eso dice ahi
    opcion = obj.menu();
    switch (opcion)
    {
    case 1:
        obj.iniciarjuego();
    case 2:
        obj.instrucciones();
    case 3:
        obj.creditos();
    case 4:
        return 0;
    default:
        break;
    }


    return 0;
}
