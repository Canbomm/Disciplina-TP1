#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"

#ifndef controladorasApresentacao_h_incluidas
#define controladorasApresentacao_h_incluidas

class cntrIAInicial{
    private:
        // Usuario que esta logado no sistema
        Matricula matricula;
        IACadastroAutenticacao *cntrIACadastroAutenticacao;
        IAUsuario *cntrIAUsuario;
        IAProjetoTarefa *cntrIAProjetoTarefa;
    public:
        void setcntrIACadastroAutenticacao(IACadastroAutenticacao*);
        void setcntrIAUsuario(IAUsuario*);
        void setcntrIAProjetoTarefa(IAProjetoTarefa*);
        void executar();
};

void inline cntrIAInicial::setcntrIACadastroAutenticacao(IACadastroAutenticacao* cntrIACadastroAutenticacao){
    this->cntrIACadastroAutenticacao = cntrIACadastroAutenticacao;
}

void inline cntrIAInicial::setcntrIAUsuario(IAUsuario* cntrIAUsuario){
    this->cntrIAUsuario = cntrIAUsuario;
}

void inline cntrIAInicial::setcntrIAProjetoTarefa(IAProjetoTarefa* cntrIAProjetoTarefa){
    this->cntrIAProjetoTarefa = cntrIAProjetoTarefa;
}

class cntrIACadastroAutenticacao:public IACadastroAutenticacao {
    private:
        ISCadastroAutenticacao *cntrISCadastroAutenticacao;
    public:
        Matricula executar();
        bool cadastrar();
        Matricula autenticar();
        Matricula desautenticar();
        void setcntrISCadastroAutenticacao(ISCadastroAutenticacao*);
};

void inline cntrIACadastroAutenticacao::setcntrISCadastroAutenticacao(ISCadastroAutenticacao *cntrISCadastroAutenticacao){
    this->cntrISCadastroAutenticacao = cntrISCadastroAutenticacao;
};

class cntrIAUsuario:public IAUsuario{
    private:
        ISUsuario *cntrISUsuario;
    public:
        Matricula executar(Matricula);
        void setcntrISUsuario(ISUsuario*);
};

void inline cntrIAUsuario::setcntrISUsuario(ISUsuario *cntrISUsuario){
    this->cntrISUsuario = cntrISUsuario;
};

class cntrIAProjetoTarefa:public IAProjetoTarefa{
    private:
        ISTarefa *cntrISTarefa;
        ISProjeto *cntrISProjeto;
        void tela_projeto(Matricula);
        void tela_tarefa(Matricula);
    public:
        void executar(Matricula);
        void setcntrISProjeto(ISProjeto*);
        void setcntrISTarefa(ISTarefa*);
};

void inline cntrIAProjetoTarefa::setcntrISTarefa(ISTarefa *cntrISTarefa){
    this->cntrISTarefa = cntrISTarefa;
};

void inline cntrIAProjetoTarefa::setcntrISProjeto(ISProjeto *cntrISProjeto){
    this->cntrISProjeto = cntrISProjeto;
};

#endif // controladorasApresentacao_h_incluidas
