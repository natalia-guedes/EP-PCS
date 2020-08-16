#ifndef PERFIL_H
#define PERFIL_H

#include "Publicacao.h"
#include "RedeSocial.h"
#include <list>
#include <vector>

#include <iostream>
#include <stdexcept>

using namespace std;

class Publicacao;

class Perfil
{
public:

    Perfil(string nome);
    Perfil(int id, string nome);
    virtual ~Perfil();

    static void setUltimoId(int ultimoId);
    static int getUltimoId();

    int getId();
    string getNome();

    virtual void adicionarSeguidor(Perfil* seguidor);

    virtual void publicar(string texto);
    virtual void publicar(string texto, string data);
    virtual void receber(Publicacao* p)=0;

    virtual list<Publicacao*>* getPublicacoesFeitas();
    virtual list<Publicacao*>* getPublicacoesRecebidas();
    virtual vector<Perfil*>* getSeguidores();

    virtual void imprimir();


protected:
    string nome;
    list<Publicacao*>* recebidas;
    int id;
    static int ultimoId;
    vector<Perfil*>* seguidores;
    list<Publicacao*>* feitas;

private:


};
#endif // PERFIL_H

