#ifndef PESSOA_H
#define PESSOA_H

#include "Perfil.h"

class Pessoa : public Perfil
{
    public:
        Pessoa(int numeroUSP, string nome, string email);
        Pessoa(int id, int numeroUSP, string nome, string email);
        virtual ~Pessoa()=0;
        int getNumeroUSP();
        string getEmail();
        virtual void receber(Publicacao* p);

    protected:
        int numeroUSP;
        string email;

    private:
};

#endif // PESSOA_H
