#include "controladorasApresentacao.h"
#include "controladorasServico.h"
#include "builders.h"

using namespace std;

int main(){
    BuilderSistema *builder;
    builder = new BuilderSistema();

    cntrIAInicial *CntrIAInicial;
    CntrIAInicial = builder->construir();

    CntrIAInicial->executar();

    return 0;
}
