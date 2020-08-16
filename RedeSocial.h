#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include <iostream>
#include <vector>

#include "Perfil.h"

using namespace std;

class Perfil;
class RedeSocial {
public:
    RedeSocial();
    virtual ~RedeSocial();

    vector<Perfil*>* getPerfis();
    Perfil* getPerfil(int id);

    void adicionar(Perfil* perfil);
    virtual void imprimir();

protected:

private:
    vector<Perfil*>* perfis;

};

#endif // REDESOCIAL_H

