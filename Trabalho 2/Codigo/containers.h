#include "entidades.h"
#include <map>
#include <list>

#ifndef containers_h_incluido
#define containers_h_incluido

using namespace std;

class containerUsuario{
    private:
        // A chave do map e uma matricula de usuario.
        map<string, Usuario> container;
        static containerUsuario *instancia;
        containerUsuario(){};
    public:
        static containerUsuario* getInstancia();
        bool cadastrar(Usuario);
        void descadastrar(Matricula);
        bool editar(Matricula, Usuario);
        Matricula autenticar(Usuario);
        Usuario consultar(Matricula);
};


class containerProjeto{
    private:
        // A chave do map e um codigo de projeto.
        map<string, Projeto> container;
        static containerProjeto *instancia;
        containerProjeto(){}
    public:
        static containerProjeto* getInstancia();
        bool adicionar(Projeto);
        bool excluir(Codigo);
        bool editar(Projeto);
        Projeto consultar(Codigo);
};

class containerTarefa{
    private:
        // A chave do map e um codigo de tarefa.
        map<string, Tarefa> container;
        static containerTarefa *instancia;
        containerTarefa(){}
    public:
        static containerTarefa* getInstancia();
        bool adicionar(Tarefa);
        bool excluir(Codigo);
        bool editar(Tarefa);
        Tarefa consultar(Codigo);
};

#endif // containers_h_incluido
