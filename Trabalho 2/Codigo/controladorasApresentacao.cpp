#include "controladorasApresentacao.h"

#ifndef conio_h_incluido
#define conio_h_incluido
#include <conio.h>
#endif

void cntrIAInicial::executar(){
    system("cls");
    char opcao1[]="1- Menu de Cadastro e Autenticacao";
    char opcao2[]="2- Menu do Usuario";
    char opcao3[]="3- Menu de projetos e tarefas";
    char opcao4[]="4- Encerrar Programa";
    char aviso_selecao[]="Digite o valor da operacao desejada: ";
    char erro[]="Valor inserido invalido";
    char nao_cadastrado[]="Usuario nao autenticado, por favor selecione a opcao 1.";


    while (true){
        cout << opcao1 << endl;
        cout << opcao2 << endl;
        cout << opcao3 << endl;
        cout << opcao4 << endl;
        cout << aviso_selecao << endl;

        string opcao;
        getline(cin,opcao);

        if (opcao == "1") {
            matricula = cntrIACadastroAutenticacao->executar();
        }
        else if (opcao == "4") {
                    break;
        }
        else {
            if (matricula.getValor() != ""){
                if (opcao == "2") {
                    matricula = cntrIAUsuario->executar(matricula);
                }
                else if (opcao == "3") {
                    cntrIAProjetoTarefa->executar(matricula);
                }
                else{
                    cout << erro << endl;
                }
            }
            else {
                system("cls");
                cout << nao_cadastrado << endl;
                cout << endl;
            }
        }
    }
    return;
}

Matricula cntrIACadastroAutenticacao::executar(){
    system("cls");
    char opcao1[]="1- Autenticar";
    char opcao2[]="2- Cadastrar";
    char opcao3[]="3- Desautenticar";
    char opcao4[]="4- Voltar a tela anterior";
    char aviso_selecao[]="Digite o valor da operacao desejada: ";
    char erro[]="Valor inserido invalido";

    char sucesso_cadastro[]="Sucesso no cadastro";
    char falha_cadastro[]="Falha no cadastro";

    char sucesso_autenticar[]="Usuario autenticado com sucesso";
    char falha_autenticar[]="Usuario nao autenticado";

    char sucesso_desautenticar[]="Usuario desautenticado com sucesso";

    Matricula matricula;

    string opcao;

    while (true){
        cout << opcao1 << endl;
        cout << opcao2 << endl;
        cout << opcao3 << endl;
        cout << opcao4 << endl;
        cout << aviso_selecao << endl;

        getline(cin,opcao);

        if (opcao == "1") {
            matricula = autenticar();
            if (matricula.getValor() != ""){
                system("cls");
                cout << sucesso_autenticar << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_autenticar << endl;
                cout << endl;
            }
        }
        else if (opcao == "2") {
            if (cadastrar()){
                system("cls");
                cout << sucesso_cadastro << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_cadastro << endl;
                cout << endl;
            }
        }
        else if (opcao == "3") {
            system("cls");
            matricula = desautenticar();
            cout << sucesso_desautenticar << endl;
            cout << endl;
        }
        else if (opcao == "4") {
            system("cls");
            return matricula;
        }
        else{
            system("cls");
            cout << erro << endl;
            cout << endl;
        }
    }
}

bool cntrIACadastroAutenticacao::cadastrar(){
    system("cls");
    char pedido_matricula[]="Digite uma matricula:";
    char pedido_nome[]="Digite um nome:";
    char pedido_senha[]="Digite uma senha:";
    char erro[]="Valor inserido invalido, tente novamente";

    string matricula;
    string nome;
    string senha;

    cout << pedido_matricula << endl;
    getline(cin, matricula);
    cout << pedido_nome << endl;
    getline(cin, nome);
    cout << pedido_senha << endl;
    getline(cin, senha);

    return cntrISCadastroAutenticacao->cadastrar(nome,matricula,senha);
};

Matricula cntrIACadastroAutenticacao::autenticar(){
    system("cls");
    char pedido_matricula[]="Digite sua matricula:";
    char pedido_senha[]="Digite sua senha:";
    char erro[]="Valor inserido invalido, tente novamente";

    string matricula;
    string senha;

    cout << pedido_matricula << endl;
    getline(cin, matricula);
    cout << pedido_senha << endl;
    getline(cin, senha);

    return cntrISCadastroAutenticacao->autenticar(matricula,senha);
};

Matricula cntrIACadastroAutenticacao::desautenticar(){
    return cntrISCadastroAutenticacao->desautenticar();
}

Matricula cntrIAUsuario::executar(Matricula matricula){
    system("cls");
    char opcao1[]="1- Descadastrar";
    char opcao2[]="2- Editar";
    char opcao3[]="3- Consultar";
    char opcao4[]="4- Voltar a tela anterior";
    char aviso_selecao[]="Digite o valor da operacao desejada: ";
    char erro[]="Valor inserido invalido, tente novamente";
    char confirmaDescadastrar[]="Tem certeza que deseja descadastrar? (s/n)";

    char sucesso_descadastrar[]="Usuario descadastrado com sucesso";

    char sucesso_edicao[]="Usuario editado com sucesso";

    char pedido_novo_nome[]="Digite um novo nome:";
    char pedido_nova_senha[]="Digite uma nova senha:";

    char dados_conta[]="Esses sao os dados da conta:";
    char texto_matricula[]="Matricula: ";
    char texto_nome[]="Nome: ";
    char texto_senha[]="Senha: ";
    char mostrar_senha[]="Deseja mostrar a senha na tela? (s/n)";
    char voltar_tela[]="Digite qualquer coisa para sair desta tela";

    while (true){
        cout << opcao1 << endl;
        cout << opcao2 << endl;
        cout << opcao3 << endl;
        cout << opcao4 << endl;
        cout << aviso_selecao << endl;

        string opcao;
        getline(cin, opcao);

        if (opcao == "1"){
            system("cls");
            string confirmacao;
            cout << confirmaDescadastrar << endl;
            getline(cin, confirmacao);

            if (confirmacao == "s"){
                // Como o usuario necessariamente precisa estar autenticado para acessar essa area
                // o processo de descadastramento nao deveria nunca falhar.
                cntrISUsuario->descadastrar(matricula);
                system("cls");
                cout << sucesso_descadastrar << endl;
                cout << endl;

                // Resetando a matricula, para 'desautenticar' o usuario.
                Matricula matricula_resetada;
                return matricula_resetada;
            }
        }
        else if (opcao == "2"){
            system("cls");
            Usuario novo_usuario;
            Nome novo_nome;
            Senha nova_senha;

            while(true){
                string novo_nome_str;
                string nova_senha_str;
                cout << pedido_novo_nome << endl;
                getline(cin,novo_nome_str);
                cout << pedido_nova_senha << endl;
                getline(cin,nova_senha_str);

                try{
                    novo_nome.setValor(novo_nome_str);
                    nova_senha.setValor(nova_senha_str);
                    break;
                }
                catch(...){
                    system("cls");
                    cout << erro << endl;
                    cout << endl;
                }
            }
            novo_usuario.setMatricula(matricula);
            novo_usuario.setNome(novo_nome);
            novo_usuario.setSenha(nova_senha);

            cntrISUsuario->editar(matricula, novo_usuario);

            system("cls");
            cout << sucesso_edicao << endl;
            cout << endl;
        }
        else if (opcao == "3"){
            system("cls");
            Usuario usuario;
            usuario = cntrISUsuario->consultar(matricula);

            string matricula_str;
            string nome_str;
            string senha_str;
            string deseja_mostrar_senha;

            matricula_str = usuario.getMatricula().getValor();
            nome_str = usuario.getNome().getValor();
            senha_str = usuario.getSenha().getValor();

            cout << dados_conta << endl;
            cout << endl;
            cout << texto_matricula << matricula_str << endl;
            cout << texto_nome << nome_str << endl;
            cout << endl;

            cout << mostrar_senha << endl;
            getline(cin,deseja_mostrar_senha);

            if (deseja_mostrar_senha == "s"){
                cout << texto_senha << senha_str << endl;
            }
            cout << endl;
            cout << voltar_tela << endl;
            getline(cin,deseja_mostrar_senha);
            system("cls");
        }
        else if (opcao == "4"){
            system("cls");
            return matricula;
        }
        else {
            system("cls");
            cout << erro << endl;
            cout << endl;
        }
    }
}

void cntrIAProjetoTarefa::executar(Matricula matricula){
    system("cls");
    char opcao1[]="1- Acessar menu de projetos";
    char opcao2[]="2- Acessar menu de tarefas";
    char opcao3[]="3- Voltar a tela anterior";
    char aviso_selecao[]="Digite o valor da operacao desejada: ";
    char erro[]="Valor inserido invalido, tente novamente";

    while(true){
        cout << opcao1 << endl;
        cout << opcao2 << endl;
        cout << opcao3 << endl;
        cout << aviso_selecao << endl;

        string opcao;
        getline(cin, opcao);

        if (opcao == "1"){
            tela_projeto(matricula);
        }
        else if (opcao == "2"){
            tela_tarefa(matricula);
        }
        else if (opcao == "3"){
            system("cls");
            break;
        }
        else{
            system("cls");
            cout << erro << endl;
            cout << endl;
        }
    };
}

void cntrIAProjetoTarefa::tela_projeto(Matricula matricula){
    system("cls");
    char titulo_menu[]="Menu de Projetos";
    char opcao1[]="1- Adicionar";
    char opcao2[]="2- Editar";
    char opcao3[]="3- Excluir";
    char opcao4[]="4- Consultar";
    char opcao5[]="5- Voltar a tela anterior";
    char aviso_selecao[]="Digite o valor da operacao desejada: ";
    char erro[]="Valor inserido invalido, tente novamente";

    char nome_projeto[]="Digite o nome do projeto:";
    char nome_codigo[]="Digite o codigo do projeto:";
    char nome_descricao[]="Digite a descricao do projeto:";

    char sucesso_adicao[]="Projeto adicionado com sucesso";
    char falha_adicao[]="Falha na adicao do projeto";

    char pedido_codigo[]="Digite o codigo do projeto que deseja alterar:";

    char novo_nome[]="Digite um novo nome para o projeto:";
    char nova_descricao[]="Digite uma nova descricao para o projeto:";

    char sucesso_exclusao[]="Projeto excluido com sucesso";
    char falha_exclusao[]="Projeto nao foi excluido";

    char consulta_codigo[]="Codigo do projeto: ";
    char consulta_nome[]="Nome do projeto: ";
    char consulta_descricao[]="Descricao do projeto: ";
    char falha_consulta[]="Falha no acesso do projeto solicitado";

    char voltar_tela[]="Digite qualquer coisa para voltar a tela anterior.";

    while (true){
        cout << titulo_menu << endl;
        cout << opcao1 << endl;
        cout << opcao2 << endl;
        cout << opcao3 << endl;
        cout << opcao4 << endl;
        cout << opcao5 << endl;
        cout << aviso_selecao << endl;

        string opcao;
        getline(cin, opcao);

        if (opcao == "1"){
            system("cls");

            string nome;
            string codigo;
            string descricao;

            cout << nome_projeto << endl;
            getline(cin,nome);
            cout << nome_codigo << endl;
            getline(cin,codigo);
            cout << nome_descricao << endl;
            getline(cin,descricao);

            if (cntrISProjeto->adicionar(nome,codigo,descricao)){
                system("cls");
                cout << sucesso_adicao << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_adicao << endl;
                cout << endl;
            }
        }
        else if (opcao == "2"){
            system("cls");

            string codigo;
            string nome;
            string descricao;

            cout << pedido_codigo << endl;
            getline(cin,codigo);
            cout << novo_nome << endl;
            getline(cin,nome);
            cout << nova_descricao << endl;
            getline(cin,descricao);

            if (cntrISProjeto->editar(nome,codigo,descricao)){
                system("cls");
                cout << sucesso_adicao << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_adicao << endl;
                cout << endl;
            }
        }
        else if (opcao == "3"){
            system("cls");
            string codigo;

            cout << pedido_codigo << endl;
            getline(cin,codigo);

            if (cntrISProjeto->excluir(codigo)){
                system("cls");
                cout << sucesso_exclusao << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_exclusao << endl;
                cout << endl;
            }
        }
        else if (opcao == "4"){
            system("cls");
            string codigo;

            cout << pedido_codigo << endl;
            getline(cin,codigo);

            Projeto projeto;
            projeto = cntrISProjeto->consultar(codigo);

            system("cls");
            cout << consulta_codigo << projeto.getCodigo().getValor() << endl;
            cout << consulta_nome << projeto.getNome().getValor() << endl;
            cout << consulta_descricao << projeto.getDescricao().getValor() << endl;
            cout << endl;
            cout << voltar_tela << endl;
            getline(cin,codigo);
            system("cls");
        }
        else if (opcao == "5"){
            system("cls");
            break;
        }
        else{
            system("cls");
            cout << erro << endl;
            cout << endl;
        }
    }
}

void cntrIAProjetoTarefa::tela_tarefa(Matricula matricula){
    system("cls");
    char titulo_menu[]="Menu de Tarefas";
    char opcao1[]="1- Adicionar";
    char opcao2[]="2- Editar";
    char opcao3[]="3- Excluir";
    char opcao4[]="4- Consultar";
    char opcao5[]="5- Voltar a tela anterior";
    char aviso_selecao[]="Digite o valor da operacao desejada: ";
    char erro[]="Valor inserido invalido, tente novamente";

    char nome_tarefa[]="Digite o nome da tarefa:";
    char nome_codigo[]="Digite o codigo da tarefa:";
    char nome_disciplina[]="Digite uma disciplina para a tarefa:";
    char nome_inicio[]="Digite a data de inicio da tarefa:";
    char nome_final[]="Digite a data final da tarefa:";

    char sucesso_adicao[]="Tarefa adicionada com sucesso";
    char falha_adicao[]="Falha na adicao da tarefa";

    char pedido_codigo[]="Digite o codigo da tarefa que deseja alterar:";

    char novo_nome[]="Digite um novo nome para a tarefa:";
    char nova_disciplina[]="Digite uma nova disciplina para a tarefa:";
    char novo_inicio[]="Digite uma nova data de inicio para a tarefa:";
    char novo_final[]="Digite uma nova data final para a tarefa:";

    char sucesso_exclusao[]="Tarefa excluida com sucesso";
    char falha_exclusao[]="Tarefa nao foi excluida";

    char consulta_codigo[]="Codigo da tarefa: ";
    char consulta_nome[]="Nome da tarefa: ";
    char consulta_disciplina[]="Disciplina: ";
    char consulta_inicio[]="Data de inicio: ";
    char consulta_final[]="Data final: ";
    char falha_consulta[]="Falha no acesso da tarefa solicitada";

    char voltar_tela[]="Digite qualquer coisa para voltar a tela anterior.";

    while (true){
        cout << titulo_menu << endl;
        cout << opcao1 << endl;
        cout << opcao2 << endl;
        cout << opcao3 << endl;
        cout << opcao4 << endl;
        cout << opcao5 << endl;
        cout << aviso_selecao << endl;

        string opcao;
        getline(cin, opcao);

        if (opcao == "1"){
            system("cls");

            string nome;
            string codigo;
            string inicio;
            string termino;
            string disciplina;

            cout << nome_tarefa << endl;
            getline(cin,nome);
            cout << nome_codigo << endl;
            getline(cin,codigo);
            cout << nome_inicio << endl;
            getline(cin,inicio);
            cout << nome_final << endl;
            getline(cin,termino);
            cout << nome_disciplina << endl;
            getline(cin,disciplina);

            if (cntrISTarefa->adicionar(nome,codigo,inicio,termino,disciplina)){
                system("cls");
                cout << sucesso_adicao << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_adicao << endl;
                cout << endl;
            }
        }
        else if (opcao == "2"){
            system("cls");

            string nome;
            string codigo;
            string inicio;
            string termino;
            string disciplina;

            cout << pedido_codigo << endl;
            getline(cin,codigo);
            cout << novo_nome << endl;
            getline(cin,nome);
            cout << novo_inicio << endl;
            getline(cin,inicio);
            cout << novo_final << endl;
            getline(cin,termino);
            cout << nova_disciplina << endl;
            getline(cin,disciplina);

            if (cntrISTarefa->editar(codigo,nome,inicio,termino,disciplina)){
                system("cls");
                cout << sucesso_adicao << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_adicao << endl;
                cout << endl;
            }
        }
        else if (opcao == "3"){
            system("cls");
            string codigo;

            cout << pedido_codigo << endl;
            getline(cin,codigo);

            if (cntrISTarefa->excluir(codigo)){
                system("cls");
                cout << sucesso_exclusao << endl;
                cout << endl;
            }
            else{
                system("cls");
                cout << falha_exclusao << endl;
                cout << endl;
            }
        }
        else if (opcao == "4"){
            system("cls");
            string codigo;

            cout << pedido_codigo << endl;
            getline(cin,codigo);

            Tarefa tarefa;
            tarefa = cntrISTarefa->consultar(codigo);

            system("cls");
            cout << consulta_codigo << tarefa.getCodigo().getValor() << endl;
            cout << consulta_nome << tarefa.getNome().getValor() << endl;
            cout << consulta_inicio << tarefa.getInicio().getValor() << endl;
            cout << consulta_final << tarefa.getTermino().getValor() << endl;
            cout << consulta_disciplina << tarefa.getDisciplina().getValor() << endl;
            cout << endl;
            cout << voltar_tela << endl;
            getline(cin,codigo);
            system("cls");
        }
        else if (opcao == "5"){
            system("cls");
            break;
        }
        else{
            system("cls");
            cout << erro << endl;
            cout << endl;
        }
    }
}
