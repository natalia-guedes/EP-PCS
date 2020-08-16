#ifndef EVENTO_H
#define EVENTO_H

#include "Publicacao.h"
#include "Perfil.h"

class Evento : public Publicacao
{
    public:
        Evento(Perfil* autor, string texto, string data);
        virtual ~Evento();
        string getData();
        virtual void curtir(Perfil* quemCurtiu);

    protected:
        string data;

    private:
};

#endif // EVENTO_H
