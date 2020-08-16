#include "Perfil.h"
#include "Evento.h"
#include "Disciplina.h"
#include "Pessoa.h"
#include "Mensagem.h"
#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>

using namespace std;

int Perfil::ultimoId=0;

Perfil::Perfil(string nome){
    this->nome = nome;
    Perfil :: ultimoId++;
    this->id=ultimoId;
    recebidas=new list<Publicacao*>();
    feitas=new list<Publicacao*>();
    seguidores=new vector<Perfil*>();
}

Perfil::Perfil(int id, string nome)
{
    this->nome=nome;
    this->id=id;
    recebidas=new list<Publicacao*>();
    feitas=new list<Publicacao*>();
    seguidores=new vector<Perfil*>();
}


// Destrutor
Perfil::~Perfil(){
    cout << endl <<"Destrutor de perfil: " << nome << " - Quantidade de publicacoes feitas: "<< feitas->size() << endl;
    // COMPLETE
    list<Publicacao*>::iterator i = feitas->begin();
    while (i != feitas->end()){
        delete (*i);
        i++;
    }
    delete feitas;

    cout << "Perfil deletado" << endl;

}

void Perfil::adicionarSeguidor(Perfil* seguidor){
    for (unsigned int i = 0; i < seguidores->size(); i++){
        if (seguidores->at(i)==seguidor){
            throw new invalid_argument ("Ja e seguidor");
        }
    }
    if (seguidor == this){
        throw new invalid_argument ("Nao pode adicionar o proprio perfil");
    }
    else {
        this->seguidores->push_back(seguidor);
        //adicionar publicação
        Disciplina *p2 = dynamic_cast<Disciplina*>(this);
        if (p2 == NULL) {
            Mensagem *p = new Mensagem (this, "Novo seguidor: " + seguidor->nome );
            this->receber(p);
        }
    }
}


string Perfil::getNome() {
	return nome;
}

void Perfil::publicar(string texto){
    feitas->push_back (new Mensagem (this,texto));
    for (unsigned int i = 0; i < seguidores->size(); i++) {
        seguidores->at(i)->receber(feitas->back());
    }
}

void Perfil::publicar(string texto, string data)
{
    feitas->push_back (new Evento (this,texto,data));
    for (unsigned int i = 0; i < seguidores->size(); i++) {
        seguidores->at(i)->receber(feitas->back());
    }
}

list<Publicacao*>* Perfil::getPublicacoesFeitas()
{
    return feitas;
}

list<Publicacao*>* Perfil::getPublicacoesRecebidas()
{
    return recebidas;
}


vector<Perfil*>* Perfil::getSeguidores()
{
    return seguidores;
}

int Perfil::getId()
{
    return this->id;
}

int Perfil::getUltimoId()
{
    return Perfil::ultimoId;
}

void Perfil::setUltimoId(int ultimoId)
{
    Perfil :: ultimoId=ultimoId;
}


void Perfil::imprimir() {
   Disciplina *p2 = dynamic_cast<Disciplina*>(this);
    if (p2 != NULL) {
        cout << endl<< p2->getSigla() <<"- " << p2->getNome() << endl;
    }
    Pessoa *p1 = dynamic_cast<Pessoa*>(this);
    if (p1 != NULL) {
        cout << endl<< p1->getNumeroUSP() <<"- " << p1->getNome() << endl;
    }

    if (seguidores->empty()==false){
        cout <<"Seguidor: "<< seguidores->size()<< endl;
    }
    else
        cout << "Sem seguidor " << endl;
    cout << "-------" << endl;

}

