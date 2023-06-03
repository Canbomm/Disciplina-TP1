#include "testes.h"

bool Teste_unidade::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return fracassou;
};


// Testes dos dominios
void T_U_Codigo::setUp(){
    codigo = new Codigo();
    fracassou = false;
};

void T_U_Codigo::testarCenarioValido(){
    try{
        codigo->setValor(codigo_valido);
        if (codigo->getValor() != codigo_valido){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Codigo::testarCenarioInvalido(){
    try{
        codigo->setValor(codigo_invalido);
        fracassou = true;
    }
    catch(...){
        if (codigo->getValor() == codigo_invalido){
            fracassou = true;
        };
    };
};

void T_U_Codigo::tearDown(){
    delete codigo;
};

void T_U_Data::setUp(){
    data = new Data();
    fracassou = false;
};

void T_U_Data::testarCenarioValido(){
    try{
        data->setValor(data_valida);
        if (data->getValor() != data_valida){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Data::testarCenarioInvalido(){
    try{
        data->setValor(data_invalida);
        fracassou = true;
    }
    catch(...){
        if (data->getValor() == data_invalida){
            fracassou = true;
        };
    };
};

void T_U_Data::tearDown(){
    delete data;
};

void T_U_Matricula::setUp(){
    matricula = new Matricula();
    fracassou = false;
};

void T_U_Matricula::testarCenarioValido(){
    try{
        matricula->setValor(matricula_valida);
        if (matricula->getValor() != matricula_valida){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Matricula::testarCenarioInvalido(){
    try{
        matricula->setValor(matricula_invalida);
        fracassou = true;
    }
    catch(...){
        if (matricula->getValor() == matricula_invalida){
            fracassou = true;
        };
    };
};

void T_U_Matricula::tearDown(){
    delete matricula;
};

void T_U_Nome::setUp(){
    nome = new Nome();
    fracassou = false;
};

void T_U_Nome::testarCenarioValido(){
    try{
        nome->setValor(nome_valido);
        if (nome->getValor() != nome_valido){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Nome::testarCenarioInvalido(){
    try{
        nome->setValor(nome_invalido);
        fracassou = true;
    }
    catch(...){
        if (nome->getValor() == nome_invalido){
            fracassou = true;
        };
    };
};

void T_U_Nome::tearDown(){
    delete nome;
};

void T_U_Senha::setUp(){
    senha = new Senha();
    fracassou = false;
};

void T_U_Senha::testarCenarioValido(){
    try{
        senha->setValor(senha_valida);
        if (senha->getValor() != senha_valida){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Senha::testarCenarioInvalido(){
    try{
        senha->setValor(senha_invalida);
        fracassou = true;
    }
    catch(...){
        if (senha->getValor() == senha_invalida){
            fracassou = true;
        };
    };
};

void T_U_Senha::tearDown(){
    delete senha;
};

void T_U_Texto::setUp(){
    texto = new Texto();
    fracassou = false;
};

void T_U_Texto::testarCenarioValido(){
    try{
        texto->setValor(texto_valido);
        if (texto->getValor() != texto_valido){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Texto::testarCenarioInvalido(){
    try{
        texto->setValor(texto_invalido);
        fracassou = true;
    }
    catch(...){
        if (texto->getValor() == texto_invalido){
            fracassou = true;
        };
    };
};

void T_U_Texto::tearDown(){
    delete texto;
};

void T_U_Disciplina::setUp(){
    disciplina = new Disciplina();
    fracassou = false;
};

void T_U_Disciplina::testarCenarioValido(){
    try{
        disciplina->setValor(disciplina_valida);
        if (disciplina->getValor() != disciplina_valida){
            fracassou = true;
        };
    }
    catch(...){
        fracassou = true;
    }
};

void T_U_Disciplina::testarCenarioInvalido(){
    try{
        disciplina->setValor(disciplina_invalida);
        fracassou = true;
    }
    catch(...){
        if (disciplina->getValor() == disciplina_invalida){
            fracassou = true;
        };
    };
};

void T_U_Disciplina::tearDown(){
    delete disciplina;
};

// Testes de entidade
bool T_U_Tarefa::run(){
    tarefa = new Tarefa();
    fracassou = false;

    nome.setValor(nome_valido);
    codigo.setValor(codigo_valido);
    inicio.setValor(inicio_valido);
    termino.setValor(termino_valido);
    disciplina.setValor(disciplina_valida);

    // executando metodos
    tarefa->setNome(nome);
    if (tarefa->getNome().getValor() != nome.getValor()){
        fracassou = true;
    };

    tarefa->setCodigo(codigo);
    if (tarefa->getCodigo().getValor() != codigo.getValor()){
        fracassou = true;
    };

    tarefa->setInicio(inicio);
    if (tarefa->getInicio().getValor() != inicio.getValor()){
        fracassou = true;
    };

    tarefa->setTermino(termino);
    if (tarefa->getTermino().getValor() != termino.getValor()){
        fracassou = true;
    };

    tarefa->setDisciplina(disciplina);
    if (tarefa->getDisciplina().getValor() != disciplina.getValor()){
        fracassou = true;
    };

    return fracassou;
}

bool T_U_Usuario::run(){
    usuario = new Usuario();
    fracassou = false;

    nome.setValor(nome_valido);
    matricula.setValor(matricula_valida);
    senha.setValor(senha_valida);

    // executando metodos
    usuario->setNome(nome);
    if (usuario->getNome().getValor() != nome.getValor()){
        fracassou = true;
    };

    usuario->setMatricula(matricula);
    if (usuario->getMatricula().getValor() != matricula.getValor()){
        fracassou = true;
    };

    usuario->setSenha(senha);
    if (usuario->getSenha().getValor() != senha.getValor()){
        fracassou = true;
    };

    return fracassou;
};

bool T_U_Projeto::run(){
    projeto = new Projeto();
    fracassou = false;

    nome.setValor(nome_valido);
    codigo.setValor(codigo_valido);
    descricao.setValor(descricao_valida);

    // executando metodos
    projeto->setCodigo(codigo);
    if (projeto->getCodigo().getValor() != codigo.getValor()){
        fracassou = true;
    };

    projeto->setDescricao(descricao);
    if (projeto->getDescricao().getValor() != descricao.getValor()){
        fracassou = true;
    };

    projeto->setNome(nome);
    if (projeto->getNome().getValor() != nome.getValor()){
        fracassou = true;
    };

    return fracassou;
}
