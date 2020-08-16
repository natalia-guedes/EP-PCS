#include "Disciplina.h"
#include "list"

Disciplina::Disciplina(string sigla, string nome, Professor* responsavel): Perfil (nome)
{
    this->sigla=sigla;
    this->responsavel=responsavel;
    this->adicionarSeguidor(responsavel);

}

Disciplina::Disciplina(int id, string sigla, string nome, Professor* responsavel): Perfil (id,nome)
{
    this->sigla=sigla;
    this->responsavel=responsavel;
}


Disciplina::~Disciplina()
{

}
string Disciplina::getSigla()
{
    return sigla;
}

Professor* Disciplina::getResponsavel()
{
    return responsavel;
}

void Disciplina::receber(Publicacao* p)
{
    recebidas->push_back(p);
}

