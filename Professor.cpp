#include "Professor.h"

Professor::Professor(int numeroUSP, string nome, string email, string departamento): Pessoa (numeroUSP,nome,email)
{
    this->departamento=departamento;
}

Professor::Professor(int id, int numeroUSP, string nome, string email, string departamento) : Pessoa (id,numeroUSP,nome,email)
{
    this->departamento=departamento;

}

Professor::~Professor()
{
    cout << "Perfil Professor deletado" << endl;
}

string Professor::getDepartamento() {
	return departamento;
}

