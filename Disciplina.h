#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Perfil.h"
#include "Professor.h"

#include <iostream>

using namespace std;


class Disciplina : public Perfil
{
    public:
        Disciplina(string sigla, string nome, Professor* responsavel);
        Disciplina(int id, string sigla, string nome, Professor* responsavel);
        virtual ~Disciplina();
        string getSigla();
        Professor* getResponsavel();
        virtual void receber(Publicacao* p);

    private:
        string sigla;
        Professor* responsavel;
};

#endif // DISCIPLINA_H
