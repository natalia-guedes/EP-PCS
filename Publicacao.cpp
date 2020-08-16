#include "Publicacao.h"
#include <iostream>


using namespace std;

//construtor
Publicacao::Publicacao(Perfil* autor, string texto){
      this -> texto= texto;
      this ->autor=autor;
}


//desturtor
Publicacao::~Publicacao(){
    cout << "Destrutor de publicacao: " << texto << endl;
}

Perfil* Publicacao::getAutor() {
    return autor;
}


int Publicacao::getCurtidas()
{
    return curtidas;
}

void Publicacao::imprimir()
{
    cout << this->texto << " (" << this->getAutor()->getNome() << ") [" << this->curtidas << "]" << endl;
}


string Publicacao::getTexto() {
	return texto;
}
