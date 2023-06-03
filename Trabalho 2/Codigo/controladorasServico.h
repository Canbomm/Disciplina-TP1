#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "containers.h"

#ifndef controladorasServico_h_incluidas
#define controladorasServico_h_incluidas

class cntrISCadastroAutenticacao:public ISCadastroAutenticacao{
    public:
        bool cadastrar(string, string, string);
        Matricula autenticar(string, string);
        Matricula desautenticar();
};

class cntrISUsuario:public ISUsuario{
    public:
        void descadastrar(Matricula);
        bool editar(Matricula, Usuario);
        Usuario consultar(Matricula);

};

class cntrISProjeto:public ISProjeto{
    public:
        bool adicionar(string,string,string);
        bool editar(string,string,string);
        bool excluir(string);
        Projeto consultar(string);
};

class cntrISTarefa:public ISTarefa{
    public:
        bool adicionar(string,string,string,string,string);
        bool editar(string,string,string,string,string);
        bool excluir(string);
        Tarefa consultar(string);
};

#endif // controladorasServico_h_incluidas
