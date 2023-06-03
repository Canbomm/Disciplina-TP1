#include "interfaces.h"
#include "controladorasApresentacao.h"
#include "controladorasServico.h"

#ifndef builders_h_incluidos
#define builders_h_incluidos

class BuilderSistema{
    private:
        cntrIAInicial *CntrIAInicial;
        IACadastroAutenticacao *CntrIACadastroAutenticacao;
        IAUsuario *CntrIAUsuario;
        IAProjetoTarefa *CntrIAProjetoTarefa;

        ISCadastroAutenticacao *CntrISCadastroAutenticacao;
        ISUsuario *CntrISUsuario;
        ISProjeto *CntrISProjeto;
        ISTarefa *CntrISTarefa;
    public:
        cntrIAInicial* construir();
        ~BuilderSistema();
};

#endif // builders_h_incluidos
