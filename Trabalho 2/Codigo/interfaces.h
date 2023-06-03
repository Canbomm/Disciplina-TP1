#include "dominios.h"
#include "entidades.h"

#ifndef interfaces_h_incluidos
#define interfaces_h_incluidos

class ISCadastroAutenticacao;
class ISUsuario;
class ISProjeto;
class ISTarefa;

using namespace std;

// Interfaces de apresentacao
class IACadastroAutenticacao{
    public:
        virtual Matricula executar() = 0;
        virtual bool cadastrar() = 0;
        virtual Matricula autenticar() = 0;
        virtual void setcntrISCadastroAutenticacao(ISCadastroAutenticacao*) = 0;
};

class IAUsuario{
    public:
        virtual Matricula executar(Matricula) = 0;
        virtual void setcntrISUsuario(ISUsuario*) = 0;
};

class IAProjetoTarefa{
    protected:
        virtual void tela_projeto(Matricula) = 0;
        virtual void tela_tarefa(Matricula) = 0;
    public:
        virtual void executar(Matricula) = 0;
        virtual void setcntrISProjeto(ISProjeto*) = 0;
        virtual void setcntrISTarefa(ISTarefa*) = 0;
};

// Interfaces de servico
class ISCadastroAutenticacao{
    public:
        virtual bool cadastrar(string, string, string) = 0;
        virtual Matricula autenticar(string, string) = 0;
        virtual Matricula desautenticar() = 0;
};

class ISUsuario{
    public:
        virtual void descadastrar(Matricula) = 0;
        virtual bool editar(Matricula, Usuario) = 0;
        virtual Usuario consultar(Matricula) = 0;
};

class ISProjeto{
    public:
        virtual bool adicionar(string,string,string) = 0;
        virtual bool editar(string,string,string) = 0;
        virtual bool excluir(string) = 0;
        virtual Projeto consultar(string) = 0;
};

class ISTarefa{
    public:
        virtual bool adicionar(string,string,string,string,string) = 0;
        virtual bool editar(string,string,string,string,string) = 0;
        virtual bool excluir(string) = 0;
        virtual Tarefa consultar(string) = 0;
};

#endif // interfaces_h_incluidos
