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

#ifndef dominios_h_incluidos
#define dominios_h_incluidos

using namespace std;

class Dominio {
    private:
        string valor;
        string charValidos;
    protected:
        virtual void validar(string) = 0;
    public:
        bool verificarCharacteres(string, const string);
        void setValor(string);
        string getValor() const;
};

inline bool Dominio::verificarCharacteres(string charValidos, const string validar){
    return validar.find_first_not_of(charValidos) == string::npos;
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
        string digitos_validos = "0123456789";
        static const int tam_codigo = 11;
    protected:
        void validar(string);
};

class Data:public Dominio {
    private:
        string digitos_validos = "0123456789";
        static const int tam_data = 8;
        int maiores_dias_do_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
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
        string digitos_validos = "0123456789";
        string letras_maiusculas_validas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static const int tam_matricula = 8;
    protected:
        void validar(string);
};

class Nome:public Dominio {
    private:
        string digitos_validos = "0123456789";
        string letras_maiusculas_validas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string letras_validas = "abcdefghijklmnopqrstuvwxyz";
        static const int max_char = 20;
        static const int max_nomes = 3;
    protected:
        void validar(string);
};

class Senha:public Dominio {
    private:
        string digitos_validos = "0123456789";
        string letras_maiusculas_validas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static const int tam_senha = 6;
        bool tem_repetido(string);
    protected:
        void validar(string);
};

class Texto:public Dominio {
    private:
        string sinais_validos = ".,;?!:-";
        string char_texto_validos = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,;?!:- ";
        static const int max_char = 40;
        static const int min_char = 10;
    protected:
        void validar(string);
};

class Disciplina:public Dominio{
    private:
        int quant_disc = 6;
        string possiveis_disc[6] = {"Arquitetura", "Desenvolvimento", "Gerenciamento", "Implantacao", "Requisitos", "Teste"};
    protected:
        void validar(string);
};

#endif // dominios_h_incluidos
