#include "PersistenciaDaRede.h"
#include "RedeSocial.h"
#include "Perfil.h"
#include "Aluno.h"
#include "Pessoa.h"
#include "Professor.h"
#include "Disciplina.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;



PersistenciaDaRede::PersistenciaDaRede(string arquivo): arquivo(arquivo)
{
}


PersistenciaDaRede::~PersistenciaDaRede()
{
    //dtor
}

void PersistenciaDaRede::salvar(RedeSocial* r)
{
    ofstream saida;
    saida.open (arquivo);
    if (saida.fail()){
        throw new logic_error ("Erro ao escrever");
        saida.close();
    }
    else{
            int quantidadeAlunos=0;
            int quantidadeProfessores=0;
            int quantidadeDisciplinas=0;
        for (unsigned int i=0; i< r->getPerfis()->size(); i++) {
            Aluno *p2 = dynamic_cast<Aluno*>(r->getPerfis()->at(i));
            if (p2 != NULL){
                quantidadeAlunos++;
            }
            Professor*p3 = dynamic_cast<Professor*>(r->getPerfis()->at(i));
            if (p3 != NULL){
                quantidadeProfessores++;
            }
            Disciplina *p4 = dynamic_cast<Disciplina*>(r->getPerfis()->at(i));
            if (p4 != NULL){
                quantidadeDisciplinas++;
            }
        }
        saida << r->getPerfil(1)->getUltimoId()<<endl;
        saida << quantidadeAlunos<<endl;
        for (unsigned int i=0; i< r->getPerfis()->size(); i++){
            Aluno *p2 = dynamic_cast<Aluno*>(r->getPerfis()->at(i));
            if (p2!=NULL){
                saida << p2->getId()<<" "<<p2->getNumeroUSP()<<" "<<p2->getNome()<<" "<<p2->getEmail()<<endl;
            }
        }
        saida << quantidadeProfessores<<endl;
        for (unsigned int i=0; i< r->getPerfis()->size(); i++){
            Professor *p3 = dynamic_cast<Professor*>(r->getPerfis()->at(i));
            if (p3!=NULL){
                saida << p3->getId()<<" "<<p3->getNumeroUSP()<<" "<<p3->getNome()<<" "<<p3->getEmail()<<" "<<p3->getDepartamento()<<endl;
            }
        }
        saida << quantidadeDisciplinas<<endl;
        for (unsigned int i=0; i< r->getPerfis()->size(); i++){
            Disciplina *p4 = dynamic_cast<Disciplina*>(r->getPerfis()->at(i));
            if (p4!=NULL){
                saida << p4->getId()<<" "<<p4->getSigla()<<" "<<p4->getNome()<<" "<<p4->getResponsavel()->getId()<<endl;
            }
        }
        for (unsigned int i=0; i< r->getPerfis()->size(); i++) {
            for (int j=0; j< r->getPerfis()->at(i)->getSeguidores()->size(); j++){
                saida<<r->getPerfis()->at(i)->getId()<<" "<<r->getPerfis()->at(i)->getSeguidores()->at(j)->getId()<<endl;
            }
        }
    }
    saida.close();
}

RedeSocial* PersistenciaDaRede::carregar()
{
    RedeSocial* rede= new RedeSocial();
    ifstream entrada;
    entrada.open (arquivo);

    if (entrada.fail() ) {
        entrada.close();
        return rede;
        }

    string nome, email,sigla,departamento;
    int total,id,numeroUsp,idSeguidor,idResponsavel,ultimoId;

    bool eAluno=true;
    bool eProfessor,eDisciplina=false;

    entrada >> ultimoId>>total>>id>>numeroUsp>>nome>>email;
    while (entrada) {
        if (total>0 && eAluno==true){
            total--;
            Aluno* a= new Aluno(id,numeroUsp,nome,email);
            rede->adicionar(a);
            if (total==0){
                eAluno=false;
                eProfessor=true;
                entrada >> total;
                entrada>>id>>numeroUsp>>nome>>email>>departamento;
            }
            else entrada>>id>>numeroUsp>>nome>>email;
        }
        else if (total>0 && eProfessor==true){
            total--;
            Professor* p= new Professor(id,numeroUsp,nome,email,departamento);
            rede->adicionar(p);
            if (total==0){
                eDisciplina=true;
                eProfessor=false;
                entrada>>total;
                entrada >> id>>sigla>>nome>>idResponsavel;
            }
            else entrada >> id>>numeroUsp>>nome>>email>>departamento;
        }
        else if (total>0 && eDisciplina==true) {
            total--;
            Professor *p3 = dynamic_cast<Professor*>(rede->getPerfis()->at(idResponsavel));
            Disciplina* d= new Disciplina(id,sigla,nome,p3);
            rede->adicionar(d);
            if (total==0){
                eDisciplina=false;
                entrada>>id>>idSeguidor;
            }
            else entrada >> id>>sigla>>nome>>idResponsavel;
        }
        else {
            rede->getPerfil(id)->adicionarSeguidor(rede->getPerfil(idSeguidor));
            entrada>>id>>idSeguidor;
        }

        }
    if (ultimoId!=0){
        rede->getPerfil(ultimoId)->setUltimoId(ultimoId);
    }
    if (!entrada.eof()){
        delete rede;
        entrada.close();
        throw new logic_error ("Erro de leitura");
        }
    entrada.close();
    return rede;
    }
