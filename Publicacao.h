#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <iostream>

#include "Perfil.h"

using namespace std;

class Perfil;

class Publicacao
{
    public:

        // Construtor
        Publicacao(Perfil* autor, string texto);
        // Destrutor
        virtual ~Publicacao();

        // Getters
        string getTexto();
        Perfil* getAutor();

        virtual void curtir(Perfil* quemCurtiu)=0;
        virtual int getCurtidas();

        virtual void imprimir();

    protected:

        string texto;
        Perfil* autor;
        int curtidas=0;

    private:
};

#endif // PUBLICACAO_H
