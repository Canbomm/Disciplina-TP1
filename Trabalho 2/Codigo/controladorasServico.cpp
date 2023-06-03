#include "controladorasServico.h"

bool cntrISCadastroAutenticacao::cadastrar(string nome_str, string matricula_str, string senha_str){
    Matricula matricula;
    Nome nome;
    Senha senha;

    try{
        matricula.setValor(matricula_str);
        nome.setValor(nome_str);
        senha.setValor(senha_str);
    }
    catch(...){
        return false;
    }

    Usuario usuario;
    usuario.setMatricula(matricula);
    usuario.setNome(nome);
    usuario.setSenha(senha);

    containerUsuario *container;
    container = containerUsuario::getInstancia();

    return container->cadastrar(usuario);
};

Matricula cntrISCadastroAutenticacao::autenticar(string matricula_str, string senha_str){
    Matricula matricula;
    Senha senha;

    try{
        matricula.setValor(matricula_str);
        senha.setValor(senha_str);
    }
    catch(...){
        return matricula;
    }

    Usuario novo_usuario;
    novo_usuario.setMatricula(matricula);
    novo_usuario.setSenha(senha);

    containerUsuario *container;
    container = containerUsuario::getInstancia();

    return container->autenticar(novo_usuario);
}

Matricula cntrISCadastroAutenticacao::desautenticar(){
    Matricula matricula_resetada;
    return matricula_resetada;
}

void cntrISUsuario::descadastrar(Matricula matricula){
    containerUsuario *container;
    container = containerUsuario::getInstancia();

    container->descadastrar(matricula);
    // Verificar os projetos e tarefas associadas ao usuario
    // AINDA NAO FOI IMPLEMENTADO!
}

bool cntrISUsuario::editar(Matricula matricula, Usuario novo_usuario){
    containerUsuario *container;
    container = containerUsuario::getInstancia();

    container->editar(matricula, novo_usuario);
}

Usuario cntrISUsuario::consultar(Matricula matricula){
    containerUsuario *container;
    container = containerUsuario::getInstancia();

    Usuario novo_usuario;
    novo_usuario = container->consultar(matricula);
    return novo_usuario;
}

bool cntrISProjeto::adicionar(string nome_str, string codigo_str, string descricao_str){
    Texto nome;
    Codigo codigo;
    Texto descricao;

    try{
        nome.setValor(nome_str);
        codigo.setValor(codigo_str);
        descricao.setValor(descricao_str);
    }
    catch(...){
        return false;
    }

    Projeto projeto;
    projeto.setNome(nome);
    projeto.setCodigo(codigo);
    projeto.setDescricao(descricao);

    containerProjeto *container;
    container = containerProjeto::getInstancia();

    return container->adicionar(projeto);
}

bool cntrISProjeto::editar(string codigo_fornecido, string novo_nome, string nova_desc){
    Codigo codigo;
    Texto nome;
    Texto descricao;

    try{
        nome.setValor(novo_nome);
        codigo.setValor(codigo_fornecido);
        descricao.setValor(nova_desc);
    }
    catch(...){
        return false;
    }

    Projeto projeto;
    projeto.setNome(nome);
    projeto.setCodigo(codigo);
    projeto.setDescricao(descricao);

    containerProjeto *container;
    container = containerProjeto::getInstancia();

    container->editar(projeto);
}

bool cntrISProjeto::excluir(string codigo_fornecido){
    Codigo codigo;

    try{
        codigo.setValor(codigo_fornecido);
    }
    catch(...){
        return false;
    }

    containerProjeto *container;
    container = containerProjeto::getInstancia();

    container->excluir(codigo);
    // Verificar as tarefas associadas ao projeto
    // AINDA NAO FOI IMPLEMENTADO!
}

Projeto cntrISProjeto::consultar(string codigo_fornecido){
    Codigo codigo;
    Projeto projeto_resetado;

    try{
        codigo.setValor(codigo_fornecido);
    }
    catch(...){
        return projeto_resetado;
    }

    containerProjeto *container;
    container = containerProjeto::getInstancia();

    Projeto novo_projeto;
    novo_projeto = container->consultar(codigo);

    if (novo_projeto.getCodigo().getValor() != codigo.getValor()){
        return projeto_resetado;
    }
    return novo_projeto;
}

bool cntrISTarefa::adicionar(string nome_str,string codigo_str,string inicio_str,string termino_str,string disciplina_str){
    Texto nome;
    Codigo codigo;
    Data inicio;
    Data termino;
    Disciplina disciplina;

    try{
        nome.setValor(nome_str);
        codigo.setValor(codigo_str);
        inicio.setValor(inicio_str);
        termino.setValor(termino_str);
        disciplina.setValor(disciplina_str);
    }
    catch(...){
        return false;
    }

    Tarefa tarefa;
    tarefa.setNome(nome);
    tarefa.setCodigo(codigo);
    tarefa.setInicio(inicio);
    tarefa.setTermino(termino);
    tarefa.setDisciplina(disciplina);

    containerTarefa *container;
    container = containerTarefa::getInstancia();

    return container->adicionar(tarefa);
}

bool cntrISTarefa::editar(string codigo_fornecido,string novo_nome,string novo_inicio,string novo_termino,string nova_disciplina){
    Texto nome;
    Codigo codigo;
    Data inicio;
    Data termino;
    Disciplina disciplina;

    try{
        nome.setValor(novo_nome);
        codigo.setValor(codigo_fornecido);
        inicio.setValor(novo_inicio);
        termino.setValor(novo_termino);
        disciplina.setValor(nova_disciplina);
    }
    catch(...){
        return false;
    }

    Tarefa tarefa;
    tarefa.setNome(nome);
    tarefa.setCodigo(codigo);
    tarefa.setInicio(inicio);
    tarefa.setTermino(termino);
    tarefa.setDisciplina(disciplina);

    containerTarefa *container;
    container = containerTarefa::getInstancia();

    container->editar(tarefa);
}

bool cntrISTarefa::excluir(string codigo_fornecido){
    Codigo codigo;

    try{
        codigo.setValor(codigo_fornecido);
    }
    catch(...){
        return false;
    }

    containerTarefa *container;
    container = containerTarefa::getInstancia();

    container->excluir(codigo);
    // Verificar os projetos associados a tarefa
    // AINDA NAO FOI IMPLEMENTADO!
}

Tarefa cntrISTarefa::consultar(string codigo_fornecido){
    Codigo codigo;
    Tarefa tarefa_resetada;

    try{
        codigo.setValor(codigo_fornecido);
    }
    catch(...){
        return tarefa_resetada;
    }

    containerTarefa *container;
    container = containerTarefa::getInstancia();

    Tarefa nova_tarefa;
    nova_tarefa = container->consultar(codigo);

    if (nova_tarefa.getCodigo().getValor() != codigo.getValor()){
        return tarefa_resetada;
    }
    return nova_tarefa;
}