#include <iostream>
#include <fstream>
#include "RedeSocial.h"

using namespace std;

#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H


class PersistenciaDaRede
{
    public:
        PersistenciaDaRede(string arquivo);
        virtual ~PersistenciaDaRede();
        void salvar(RedeSocial* r);
        RedeSocial* carregar();
    protected:
        string arquivo;

    private:
};

#endif // PERSISTENCIADAREDE_H
