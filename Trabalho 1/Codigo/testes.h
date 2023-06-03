#ifndef testes_h_incluido
#define testes_h_incluido

#include "dominios.h"
#include "entidades.h"
#include <string>

using namespace std;

class Teste_unidade {
    protected:
        bool fracassou;
        virtual void setUp() = 0;
        virtual void tearDown() = 0;
        virtual void testarCenarioValido() = 0;
        virtual void testarCenarioInvalido() = 0;
    public:
        bool run();
};

// Testes de dominio
class T_U_Codigo:public Teste_unidade {
    private:
        string codigo_valido = "12345678912";
        string codigo_invalido = "12345b78912";
        Codigo *codigo;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

class T_U_Data:public Teste_unidade {
    private:
        string data_valida = "29-02-20";
        string data_invalida = "29-02-22";
        Data *data;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

class T_U_Matricula:public Teste_unidade {
    private:
        string matricula_valida = "ABCD1234";
        string matricula_invalida = "ABcD1234";
        Matricula *matricula;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

class T_U_Nome:public Teste_unidade {
    private:
        string nome_valido = "Caio Pinto Silva";
        string nome_invalido = "Caio Pinto Silva Rodrigues";
        Nome *nome;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

class T_U_Senha:public Teste_unidade {
    private:
        string senha_valida = "ABC34D";
        string senha_invalida = "ABB34D";
        Senha *senha;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

class T_U_Texto:public Teste_unidade {
    private:
        string texto_valido = "Eu sou um texto para testes 1 .,";
        string texto_invalido = "Eu sou um texto # para testes 1 .,";
        Texto *texto;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

class T_U_Disciplina:public Teste_unidade {
    private:
        string disciplina_valida = "Arquitetura";
        string disciplina_invalida = "Calculo";
        Disciplina *disciplina;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
};

// Testes de entidade
class T_U_Tarefa{
    private:
        string nome_valido = "Dever de casa";
        Texto nome;
        string codigo_valido = "65432178906";
        Codigo codigo;
        string inicio_valido = "01-01-00";
        Data inicio;
        string termino_valido = "31-12-99";
        Data termino;
        string disciplina_valida = "Gerenciamento";
        Disciplina disciplina;
        Tarefa *tarefa;
    protected:
        bool fracassou;
    public:
        bool run();
};

class T_U_Projeto{
    private:
        string nome_valido = "Trabalho 1";
        Texto nome;
        string codigo_valido = "09876543219";
        Codigo codigo;
        string descricao_valida = "Trabalho trabalhoso que da trabalho";
        Texto descricao;
        Projeto *projeto;
    protected:
        bool fracassou;
    public:
        bool run();
};

class T_U_Usuario{
    private:
        string nome_valido = "Carlos Alberto";
        Nome nome;
        string matricula_valida = "EFGH6789";
        Matricula matricula;
        string senha_valida = "EFG43I";
        Senha senha;
        Usuario *usuario;
    protected:
        bool fracassou;
    public:
        bool run();
};

#endif
