#include "dominios.h"
#ifndef entidades_h_incluidos
#define entidades_h_incluidos

using namespace std;

class Tarefa {
    private:
        Texto nome;
        Codigo codigo;
        Data inicio;
        Data termino;
        Disciplina disciplina;
    public:
        void setNome(Texto);
        void setCodigo(Codigo);
        void setInicio(Data);
        void setTermino(Data);
        void setDisciplina(Disciplina);
        Texto getNome();
        Codigo getCodigo();
        Data getInicio();
        Data getTermino();
        Disciplina getDisciplina();
};

inline void Tarefa::setNome(Texto nome){
    this->nome = nome;
};

inline void Tarefa::setCodigo(Codigo codigo){
    this->codigo = codigo;
};

inline void Tarefa::setInicio(Data inicio){
    this->inicio = inicio;
};

inline void Tarefa::setTermino(Data termino){
    this->termino = termino;
};

inline void Tarefa::setDisciplina(Disciplina disciplina){
    this->disciplina = disciplina;
};

inline Texto Tarefa::getNome(){
    return nome;
};

inline Codigo Tarefa::getCodigo(){
    return codigo;
};

inline Data Tarefa::getInicio(){
    return inicio;
};

inline Data Tarefa::getTermino(){
    return termino;
};

inline Disciplina Tarefa::getDisciplina(){
    return disciplina;
};

class Projeto {
    private:
        Texto nome;
        Codigo codigo;
        Texto descricao;
    public:
        void setNome(Texto);
        void setCodigo(Codigo);
        void setDescricao(Texto);
        Texto getNome();
        Codigo getCodigo();
        Texto getDescricao();
};

inline void Projeto::setNome(Texto nome){
    this->nome = nome;
};

inline void Projeto::setCodigo(Codigo codigo){
    this->codigo = codigo;
};

inline void Projeto::setDescricao(Texto descricao){
    this->descricao = descricao;
};

inline Texto Projeto::getNome(){
    return nome;
};

inline Codigo Projeto::getCodigo(){
    return codigo;
};

inline Texto Projeto::getDescricao(){
    return descricao;
};

class Usuario {
    private:
        Nome nome;
        Matricula matricula;
        Senha senha;
    public:
        void setNome(Nome);
        void setMatricula(Matricula);
        void setSenha(Senha);
        Nome getNome();
        Matricula getMatricula();
        Senha getSenha();
};

inline void Usuario::setNome(Nome nome){
    this->nome = nome;
};

inline void Usuario::setMatricula(Matricula matricula){
    this->matricula = matricula;
};

inline void Usuario::setSenha(Senha senha){
    this->senha = senha;
};

inline Nome Usuario::getNome(){
    return nome;
};

inline Matricula Usuario::getMatricula(){
    return matricula;
};

inline Senha Usuario::getSenha(){
    return senha;
};

#endif // entidades_h_incluidos
