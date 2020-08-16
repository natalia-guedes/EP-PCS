#include "RedeSocial.h"
#include "PerfilInexistente.h"
#include <iostream>
#include <vector>

using namespace std;

RedeSocial::RedeSocial()
{
    this->perfis= new vector<Perfil*>();

}
RedeSocial::~RedeSocial()
{
    for(unsigned int i = 0; i < perfis->size(); i++){
        delete perfis->at(i);
    }
    delete perfis;
}
vector<Perfil*>* RedeSocial::getPerfis()
{
    return perfis;
}

Perfil* RedeSocial::getPerfil(int id)
{
    for (unsigned int i=0; i < perfis->size(); i++){
            if (perfis->at(i)->getId() == id){
                return perfis->at(i);
            }
        }
    throw new PerfilInexistente ();

}


void RedeSocial::adicionar(Perfil* perfil){
    perfis->push_back(perfil);

}

void RedeSocial::imprimir () {
  cout << endl << "------------------------------ " << endl;
  cout << "RedeSocial: " << perfis->size() << " perfis" << endl;
  cout << "------------------------------ " << endl;
  if (perfis->empty()==true){
    cout << "Sem perfis" << endl;
    cout << "------------------------------ " << endl;
  } else {
    for (unsigned int i=0; i < perfis->size(); i++){
      perfis->at(i)->imprimir();
      cout << "------------------------------ " << endl;
    }
  }
  cout << endl;
}
