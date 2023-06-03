#include "builders.h"

cntrIAInicial* BuilderSistema::construir(){
    // Instanciando camada de apresentacao
    CntrIAInicial = new cntrIAInicial();
    CntrIACadastroAutenticacao = new cntrIACadastroAutenticacao();
    CntrIAUsuario = new cntrIAUsuario();
    CntrIAProjetoTarefa = new cntrIAProjetoTarefa();

    // Instanciando camada de servico
    CntrISCadastroAutenticacao = new cntrISCadastroAutenticacao();
    CntrISUsuario = new cntrISUsuario();
    CntrISProjeto = new cntrISProjeto();
    CntrISTarefa = new cntrISTarefa();

    // Interligando camada de apresentacao a de servico
    CntrIAInicial->setcntrIACadastroAutenticacao(CntrIACadastroAutenticacao);
    CntrIAInicial->setcntrIAUsuario(CntrIAUsuario);
    CntrIAInicial->setcntrIAProjetoTarefa(CntrIAProjetoTarefa);

    CntrIACadastroAutenticacao->setcntrISCadastroAutenticacao(CntrISCadastroAutenticacao);

    CntrIAUsuario->setcntrISUsuario(CntrISUsuario);

    CntrIAProjetoTarefa->setcntrISProjeto(CntrISProjeto);
    CntrIAProjetoTarefa->setcntrISTarefa(CntrISTarefa);

    return CntrIAInicial;
}
