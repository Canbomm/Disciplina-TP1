#ifndef string_incluida
#define string_incluida
#include <string>
#endif

#ifndef excecao_incluida
#define excecao_incluida
#include <stdexcept>
#endif

#ifndef iostream_incluida
#define iostream_incluida
#include <iostream>
#endif

#ifndef lista_incluida
#define lista_incluida
#include <list>
#endif

#ifndef dominios_h_incluidos
#define dominios_h_incluidos

using namespace std;

class Dominio {
    private:
        string valor;
    protected:
        virtual void validar(string) = 0;
    public:
        void setValor(string);
        string getValor() const;
};

inline string Dominio::getValor() const{
    return valor;
};

inline void Dominio::setValor(string entrada){
    validar(entrada);
    valor = entrada;
};

// Definindo classes que herdam de Dominio

class Codigo:public Dominio {
    private:
        static const int tam_codigo = 11;
    protected:
        void validar(string);
};

class Data:public Dominio {
    private:
        static const int tam_data = 8;
        list<int> maiores_dias_do_mes{31,28,31,30,31,30,31,31,30,31,30,31};
        static const int maior_mes = 12;
        static const int maior_ano = 99;
        static const int menor_dia = 01;
        static const int menor_mes = 01;
        static const int menor_ano = 00;
    protected:
        void validar(string);
};

class Matricula:public Dominio {
    private:
        static const int tam_matricula = 8;
    protected:
        void validar(string);
};

class Nome:public Dominio {
    private:
        static const int max_char = 20;
        static const int max_nomes = 3;
    protected:
        void validar(string);
};

class Senha:public Dominio {
    private:
        static const int tam_senha = 6;
    protected:
        void validar(string);
};

class Texto:public Dominio {
    private:
        static const int max_char = 40;
        static const int min_char = 10;
    protected:
        void validar(string);
};

class Disciplina:public Dominio{
    private:
        list<string> possiveis_disc{"Arquitetura", "Desenvolvimento", "Gerenciamento", "Implantacao", "Requisitos", "Teste"};
    protected:
        void validar(string);
};

#endif
