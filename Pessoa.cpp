#include "Pessoa.h"
#include "Perfil.h"
#include "Publicacao.h"
#include "Mensagem.h"
#include "list"
#include <stdexcept>


Pessoa::Pessoa(int numeroUSP, string nome, string email) : Perfil (nome)
{
    this->numeroUSP= numeroUSP;
    this->email=email;
}

Pessoa::Pessoa(int id, int numeroUSP, string nome, string email) : Perfil (id,nome)
{
    this->numeroUSP= numeroUSP;
    this->email=email;
}


Pessoa::~Pessoa()
{
    //dtor
}

void Pessoa::receber(Publicacao* p)
{
    recebidas->push_back(p);
}

int Pessoa::getNumeroUSP()
{
    return numeroUSP;
}

string Pessoa::getEmail()
{
    return email;
}
