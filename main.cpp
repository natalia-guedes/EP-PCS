#include "Perfil.h"
#include "Publicacao.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "Evento.h"
#include "PersistenciaDaRede.h"
#include <iostream>
#include <stdexcept>



using namespace std;

RedeSocial* CriarRedeSocial(PersistenciaDaRede* persistencia)
{
    try{
        RedeSocial* rede= persistencia->carregar();
        return rede;
    }
    catch (logic_error*e) {
        cout << "Erro: " << e->what()<<endl;
        delete e; // limpando!
    }

}

int ListarPerfis(vector<Perfil*>* perfis, int n)
{
    cout <<  endl;
    for (int i = 0; i < n; i++)
    {
        cout << perfis->at(i)->getId() << ") "<< perfis->at(i)->getNome() <<endl;
    }
    cout << endl << "Digite o Id ou 0 para cancelar: "<< endl;
    cout <<  "------------------------------ " << endl;
    int m;
    cin >>m;
    return m;
}

int Menu()
{
    int t;
    cout << endl << "Escolha uma opcao:" << endl<<"1) Cadastrar Perfil"<<endl<<"2) Cadastrar Disciplina"<<endl
    <<"3) Logar"<<endl<<"0) Terminar"<<endl;
    cout << "------------------------------ " << endl;
    cin >>t;
    return t;
}

int MenuPerfil(Perfil* perfil)
{
    int n;
    perfil->imprimir();
    cout << endl << "Escolha uma opcao:" << endl<<"1) Ver publicacoes feitas"<<endl<<"2) Ver publicacaoes recebidas"<<endl
    <<"3) Fazer publicacao"<<endl<<"4) Seguir Perfil"<<endl<<"0) Deslogar"<<endl;
    //if é uma disciplina
    cin >>n;
    cout << "------------------------------ " << endl;
    return n;
}

void CadastrarPerfil(RedeSocial* rede)
{
    int nusp;
    string professor;
    cout <<endl <<"Informa os dados do perfil:" << endl << "Numero USP:";
    cin>>nusp;
    string nome;
    cout <<"Nome:";
    cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
    getline(cin, nome); // guardando uma linha em nome
    string email;
    cout <<"Email:";
    cin>>email;
    cout <<"Professor (s/n):" ;
    cin>>professor;
    Perfil* perfil;
    if (professor=="s"){
        string departamento;
        cout <<"Departamento:";
        cin>>departamento;
        perfil = new Professor(nusp,nome,email,departamento);
    }
    else perfil = new Aluno(nusp,nome,email);
    rede->adicionar(perfil);
}

void CadastrarDisciplina(RedeSocial* rede,vector<Perfil*>* perfis)
{
    string sigla;
    cout <<"Informa os dados da disciplina:" << endl << "Sigla:";
    cin>>sigla;
    string nome;
    cout <<"Nome:";
    cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
    getline(cin, nome); // guardando uma linha em nome
    cout <<"Responsavel:";
    Perfil* responsavel;
    int id =ListarPerfis(rede->getPerfis(),rede->getPerfis()->size());
    if (id!=0){
        responsavel=rede->getPerfil(id);
        Professor *v2 = dynamic_cast<Professor*>(responsavel);
        if (v2 != NULL) {
            Perfil*disciplina = new Disciplina(sigla,nome,v2);
            rede->adicionar(disciplina);
        }
        else cout <<"Somente professores podem ser responsaveis por disciplinas"<<endl;

    }
}

int main()
{
    cout<<"Qual e o nome do arquivo a ser carregado?"<<endl;
    int n;
    int m;
    string nomeDaRede;
    cin >>nomeDaRede;
    PersistenciaDaRede* persistencia= new PersistenciaDaRede(nomeDaRede);
    RedeSocial* rede= CriarRedeSocial(persistencia);
    bool fim= false;
    bool logado= false;
    while (fim == false) { //rede social está ligado
        n=Menu();
        if (n==0){
            fim = true;
        }
        else if (n==1){
            CadastrarPerfil(rede);
        }

        else if (n==2){
            CadastrarDisciplina(rede,rede->getPerfis());

        }
        else if (n==3){
            logado=true;
            cout << endl <<"Escolha um perfil: ";
            m=ListarPerfis(rede->getPerfis(),rede->getPerfis()->size());
            if (m==0) logado=false;
            else {
                Perfil* perfil= rede->getPerfil(m);
                while (logado==true){ // está logado em um perfil
                    int x= MenuPerfil(perfil);
                    if (x==0){
                            logado = false;
                    }
                    else if (x==1){
                      cout <<endl<< "Publicacaos feitas: "<< endl;
                      list<Publicacao*>::iterator i = perfil->getPublicacoesFeitas()->begin();
                      while (i != perfil->getPublicacoesFeitas()->end()){
                            (*i)->imprimir();
                            i++;
                            }

                    }

                    else if (x==2){
                        Disciplina *p2 = dynamic_cast<Disciplina*>(perfil);
                        if (p2 == NULL) {
                            cout << endl << "Publicacaos recebidas: "<< endl;
                            list<Publicacao*>::iterator i = perfil->getPublicacoesRecebidas()->begin();
                            int contador=1;
                            while (i != perfil->getPublicacoesRecebidas()->end()){
                                    cout<<contador<< ") ";
                                    (*i)->imprimir();
                                    contador++;
                                    i++;
                            }
                            cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
                            int curtir;
                            cin >> curtir ;
                            list<Publicacao*>::iterator j = perfil->getPublicacoesRecebidas()->begin();
                            contador=1;
                            while (j != perfil->getPublicacoesRecebidas()->end()){
                                    if (contador ==curtir){
                                        try{
                                            (*j)->curtir(perfil);
                                            cout<<contador<<endl;
                                        }
                                        catch (invalid_argument *e) {
                                            cout << "Erro: " << e->what()<<endl;
                                            delete e; // limpando!
                                            terminate();
                                            }
                                    }
                                    contador++;
                                    cout<<contador<<endl;
                                    j++;
                            }

                        }

                    }

                    else if (x==3){
                        cout << "Evento (s/n): ";
                        string evento;
                        string texto;
                        cin>>evento;
                        if (evento=="s"){
                            string data;
                            cout <<"Data: ";
                            cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                            getline(cin, data); // guardando uma linha em nome
                            cout <<"Texto: ";
                            //cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                            getline(cin, texto); // guardando uma linha em nome
                            perfil->publicar(texto,data);
                        }
                        else if (evento=="n"){
                            cout <<"Texto: ";
                            cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                            getline(cin, texto); // guardando uma linha em nome
                            perfil->publicar(texto);
                        }

                    }

                    else if (x==4){
                        Disciplina *p2 = dynamic_cast<Disciplina*>(perfil);
                        if (p2 == NULL) {
                            cout << endl <<"Perfil: ";
                            m=ListarPerfis(rede->getPerfis(),rede->getPerfis()->size());
                            try {
                                if (m!=0) rede->getPerfil(m) ->adicionarSeguidor(perfil);
                            }
                            catch (invalid_argument *e) {
                                cout << "Erro: " << e->what()<<endl;
                                delete e; // limpando!
                                terminate();
                            }


                        }
                    }
                }
            }
        }
    }
    cout<<"Deseja salvar a rede social?"<<endl<<"1)Sim"<<endl<<"2)Nao"<<endl;
    cin >>m;
    try {
        if (m==1){
            persistencia->salvar(rede);
        }
    }
    catch (logic_error *e) {
        cout << "Erro: " << e->what()<<endl;
        delete e; // limpando!
        terminate();
    }

    rede->~RedeSocial();

    return 0;
}


