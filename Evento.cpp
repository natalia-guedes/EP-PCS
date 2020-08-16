#include "Evento.h"

Evento::Evento(Perfil* autor, string texto, string data) : Publicacao (autor, texto)
{
    this->data;
}

Evento::~Evento()
{
    cout << "Destrutor de evento" << texto << endl;
}


string Evento::getData()
{
    return data;
}

void Evento::curtir(Perfil* quemCurtiu)
{
    curtidas++;
}

