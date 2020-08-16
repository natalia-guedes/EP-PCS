#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Perfil.h"
#include "Pessoa.h"

#include <iostream>

using namespace std;


class Professor : public Pessoa{
    public:
        Professor(int numeroUSP, string nome, string email, string departamento);
        Professor(int id, int numeroUSP, string nome, string email, string departamento);
        virtual ~Professor();
        string getDepartamento();

    private:
        string departamento;
};

#endif // PROFESSOR_H

