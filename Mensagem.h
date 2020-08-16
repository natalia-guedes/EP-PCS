#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Publicacao.h"
#include "Perfil.h"


class Mensagem : public Publicacao
{
    public:
        Mensagem(Perfil* autor, string texto);
        virtual ~Mensagem();
        virtual void curtir(Perfil* quemCurtiu);

    protected:

    private:
};

#endif // MENSAGEM_H
