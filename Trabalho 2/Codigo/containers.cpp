#include "containers.h"

containerUsuario* containerUsuario::instancia = nullptr;
containerProjeto* containerProjeto::instancia = nullptr;
containerTarefa* containerTarefa::instancia = nullptr;

containerUsuario* containerUsuario::getInstancia(){
    if (instancia == nullptr){
        instancia = new containerUsuario();
    }
    return instancia;
};

containerProjeto* containerProjeto::getInstancia(){
    if (instancia == nullptr){
        instancia = new containerProjeto();
    }
    return instancia;
};

containerTarefa* containerTarefa::getInstancia(){
    if (instancia == nullptr){
        instancia = new containerTarefa();
    }
    return instancia;
};

bool containerUsuario::cadastrar(Usuario usuario){
    string matricula;
    matricula = usuario.getMatricula().getValor();

    // Verificando se o usuario ja nao existe
    Usuario usuario_bd;
    usuario_bd = container[matricula];
    if (usuario_bd.getMatricula().getValor() != ""){
        return false;
    };

    container[matricula] = usuario;
    return true;
}

Matricula containerUsuario::autenticar(Usuario usuario){
    if (container.empty() == 1){
        Matricula matricula_vazia;
        return matricula_vazia;
    }

    string matricula;
    matricula = usuario.getMatricula().getValor();
    string senha;
    senha = usuario.getSenha().getValor();

    // Comparando valor com o do Container
    Usuario usuario_bd;
    usuario_bd = container[matricula];

    if (usuario_bd.getSenha().getValor() != senha){
        Matricula matricula_vazia;
        return matricula_vazia;
    }
    else{
        return usuario_bd.getMatricula();
    }
}

void containerUsuario::descadastrar(Matricula matricula){
    string matricula_str;
    matricula_str = matricula.getValor();

    container.erase(matricula_str);
};

bool containerUsuario::editar(Matricula matricula, Usuario novo_usuario){
    string matricula_str;
    matricula_str = matricula.getValor();

    // Verificando se o usuario existe
    Usuario usuario_bd;
    usuario_bd = container[matricula_str];
    if (usuario_bd.getMatricula().getValor() != ""){
        container[matricula_str] = novo_usuario;
        return true;
    };

    return false;
};

Usuario containerUsuario::consultar(Matricula matricula){
    string matricula_str;
    matricula_str = matricula.getValor();

    return container[matricula_str];
};

bool containerProjeto::adicionar(Projeto projeto){
    string codigo;
    codigo = projeto.getCodigo().getValor();

    // Verificando se o projeto ja nao existe
    Projeto projeto_bd;
    projeto_bd = container[codigo];
    if (projeto_bd.getCodigo().getValor() != ""){
        return false;
    };

    container[codigo] = projeto;
    return true;
};

bool containerProjeto::excluir(Codigo codigo){
    if (container.empty() == 1){
        return false;
    }

    string codigo_str;
    codigo_str = codigo.getValor();

    container.erase(codigo_str);
    return true;
};

bool containerProjeto::editar(Projeto projeto){
    if (container.empty() == 1){
        return false;
    }

    string codigo;
    codigo = projeto.getCodigo().getValor();

    // Verificando se o projeto existe
    Projeto projeto_bd;
    projeto_bd = container[codigo];
    if (projeto_bd.getCodigo().getValor() != ""){
        container[codigo] = projeto;
        return true;
    };

    return false;
};

Projeto containerProjeto::consultar(Codigo codigo){
    string codigo_str;
    codigo_str = codigo.getValor();

    // Verificando se existe projeto
    Projeto projeto_bd;
    projeto_bd = container[codigo_str];
    if (projeto_bd.getCodigo().getValor() != ""){
        return container[codigo_str];
    }

    Projeto projeto_resetado;
    return projeto_resetado;
};

bool containerTarefa::adicionar(Tarefa tarefa){
    string codigo;
    codigo = tarefa.getCodigo().getValor();

    // Verificando se o tarefa ja nao existe
    Tarefa tarefa_bd;
    tarefa_bd = container[codigo];
    if (tarefa_bd.getCodigo().getValor() != ""){
        return false;
    };

    container[codigo] = tarefa;
    return true;
};

bool containerTarefa::excluir(Codigo codigo){
    if (container.empty() == 1){
        return false;
    }

    string codigo_str;
    codigo_str = codigo.getValor();

    container.erase(codigo_str);
    return true;
};

bool containerTarefa::editar(Tarefa tarefa){
    if (container.empty() == 1){
        return false;
    }

    string codigo;
    codigo = tarefa.getCodigo().getValor();

    // Verificando se o tarefa existe
    Tarefa tarefa_bd;
    tarefa_bd = container[codigo];
    if (tarefa_bd.getCodigo().getValor() != ""){
        container[codigo] = tarefa;
        return true;
    };

    return false;
};

Tarefa containerTarefa::consultar(Codigo codigo){
    string codigo_str;
    codigo_str = codigo.getValor();

    // Verificando se existe tarefa
    Tarefa tarefa_bd;
    tarefa_bd = container[codigo_str];
    if (tarefa_bd.getCodigo().getValor() != ""){
        return container[codigo_str];
    }

    Tarefa tarefa_resetada;
    return tarefa_resetada;
};
