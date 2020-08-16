#include "Mensagem.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Mensagem::Mensagem(Perfil* autor, string texto) : Publicacao (autor,texto)
{
    //ctor
}

Mensagem::~Mensagem()
{
    cout << "Destrutor de Mensagens: " << texto << endl;
}


void Mensagem::curtir(Perfil* quemCurtiu)
{
    if (quemCurtiu!=this->autor) curtidas++;
    else {
            throw new invalid_argument ("Invalido");
    }
}
