#include "PerfilInexistente.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

PerfilInexistente::PerfilInexistente() :  logic_error("Perfil inexistente")
{

}

PerfilInexistente::~PerfilInexistente()
{

}
