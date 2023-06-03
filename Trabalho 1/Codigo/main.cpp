#include "dominios.h"
#include "entidades.h"
#include "testes.h"

int main(){
    // Testes de dominio
    cout << "--- Testes de dominio ---" << endl;
    T_U_Codigo teste_codigo;
    if (teste_codigo.run()){
        cout << "Teste de unidade: Codigo - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Codigo - Sucesso" << endl;
    };

    T_U_Data teste_data;
    if (teste_data.run()){
        cout << "Teste de unidade: Data - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Data - Sucesso" << endl;
    };

    T_U_Matricula teste_matricula;
    if (teste_matricula.run()){
        cout << "Teste de unidade: Matricula - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Matricula - Sucesso" << endl;
    };

    T_U_Nome teste_nome;
    if (teste_nome.run()){
        cout << "Teste de unidade: Nome - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Nome - Sucesso" << endl;
    };

    T_U_Senha teste_senha;
    if (teste_senha.run()){
        cout << "Teste de unidade: Senha - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Senha - Sucesso" << endl;
    };

    T_U_Texto teste_texto;
    if (teste_texto.run()){
        cout << "Teste de unidade: Texto - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Texto - Sucesso" << endl;
    };

    T_U_Disciplina teste_disciplina;
    if (teste_disciplina.run()){
        cout << "Teste de unidade: Disciplina - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Disciplina - Sucesso" << endl;
    };

    // Testes de entidade
    cout << "--- Testes de entidade ---" << endl;
    T_U_Tarefa teste_tarefa;
    if (teste_tarefa.run()){
        cout << "Teste de unidade: Tarefa - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Tarefa - Sucesso" << endl;
    };

    T_U_Projeto teste_projeto;
    if (teste_projeto.run()){
        cout << "Teste de unidade: Projeto - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Projeto - Sucesso" << endl;
    };

    T_U_Usuario teste_usuario;
    if (teste_usuario.run()){
        cout << "Teste de unidade: Usuario - Fracasso" << endl;
    }
    else {
        cout << "Teste de unidade: Usuario - Sucesso" << endl;
    };

    return 0;
}
