#include "dominios.h"
#include "funcoes_auxiliares.h"

using namespace std;

void Codigo::validar(string entrada){
    // Formato: DDDDDDDDDDX
    // D e X = digito de 0 a 9
    int tam_entrada = entrada.length();

    if (tam_entrada != tam_codigo){
        throw invalid_argument("Argumento invalido.");
    };

    if (is_digits(entrada) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
};

void Data::validar(string entrada){
    int tam_entrada = entrada.length();

    if (tam_entrada != tam_data){
        throw invalid_argument("Argumento invalido.");
    };

    string dia_str = entrada.substr(0,2);
    string mes_str = entrada.substr(3,2);
    string ano_str = entrada.substr(6,2);

    if (is_digits(dia_str) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
    if (is_digits(mes_str) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
    if (is_digits(ano_str) == 0){
	    throw invalid_argument("Argumento invalido.");
    };

    int dia = stoi(dia_str);
    int mes = stoi(mes_str);
    int ano = stoi(ano_str);

    if ((mes > maior_mes) || (mes < menor_mes)){
        throw invalid_argument("Argumento invalido.");
    };
    if ((ano > maior_ano) || (ano < menor_ano)){
        throw invalid_argument("Argumento invalido.");
    };

    auto max_dias_mes_atual = maiores_dias_do_mes.begin();
    advance(max_dias_mes_atual, mes-1);

    if (mes == 2){
        // verificando se o ano e bissexto, ja que o mes e fevereiro
        if ((ano % 4) == 0){
            // como e bissexto e o mes e fevereiro, o limite de dias aumenta em 1
            if ((dia-1 > *max_dias_mes_atual) || (dia < menor_dia)){
                throw invalid_argument("Argumento invalido.");
            };
        }
        else{
            // como o ano nao e bissexto, faco a verificacao normal
            if ((dia > *max_dias_mes_atual) || (dia < menor_dia)){
                throw invalid_argument("Argumento invalido.");
            };
        };
    }
    else {
        // se nao e fevereiro, nao faz diferenca ser bissexto ou nao
        if ((dia > *max_dias_mes_atual) || (dia < menor_dia)){
            throw invalid_argument("Argumento invalido.");
        };
    };
};

void Matricula::validar(string entrada){
    // Formato LLLLDDDD
    // L = letra maiúscula de A a Z
    // D = dígito de 0 a 9
    int tam_entrada = entrada.length();

    if (tam_entrada != tam_matricula){
        throw invalid_argument("Argumento invalido.");
    };

    string caracteres = entrada.substr(0,3);
    string digitos = entrada.substr(4,7);

    if (is_digits(digitos) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
    if (is_char_uppercase(caracteres) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
};

void Nome::validar(string entrada){
    // No max 3 nomes
    // No max 20 caracteres
    // Caractere = letra de A a Z (minusculo tambem) e espaco
    // Primeira letra obrigatoriamente maiscula
    // Nao pode ter espaco seguido
    if (entrada.length() > max_char){
        throw invalid_argument("Argumento invalido.");
    };

    bool primeira_letra = true;
    int total_espacos = 0;
    for (int i=0 ; i < entrada.length() ; i++){
        string char_atual;
        char_atual = entrada[i];

        if (char_atual == " "){
            primeira_letra = true;
            total_espacos += 1;

            string prox_char;
            prox_char = entrada[i+1];
            if (prox_char == " "){
                throw invalid_argument("Argumento invalido.");
            };
        }
        else {
            if (is_digits(char_atual)){
                throw invalid_argument("Argumento invalido.");
            };

            if (primeira_letra){
                if (is_char_uppercase(char_atual) != 1){
                    throw invalid_argument("Argumento invalido.");
                };
            };

            if (is_char(char_atual) != 1){
                throw invalid_argument("Argumento invalido.");
            };

            primeira_letra = false;

        };
    };
    // Com o total de espacos, podemos ter nocao de quantos nomes foram inseridos
    if (total_espacos > max_nomes-1){
        throw invalid_argument("Argumento invalido.");
    };
};

void Senha::validar(string entrada){
    // Composto de letras de A a Z ou digitos de 0 a 9
    // NAO PODE HAVER CARACTERE DUPLICADO
    // Requisito de 2 letras e 2 digitos
    if (entrada.length() != tam_senha){
        throw invalid_argument("Argumento invalido.");
    };

    if (tem_repetido(entrada)){
        throw invalid_argument("Argumento invalido.");
    };

    int min_dig = 2;
    int min_letras = 2;
    for (int i=0; i < entrada.length();i++){
        string char_atual;
        char_atual = entrada[i];

        if (is_digits(char_atual)){
            if (min_dig > 0){
                min_dig -= 1;
            };
        }
        else if (is_char_uppercase(char_atual)){
            if (min_letras > 0){
                min_letras -= 1;
            };
        }
        else {
            throw invalid_argument("Argumento invalido.");
        }
    };
    if (min_dig > 0){
        throw invalid_argument("Argumento invalido.");
    };
    if (min_letras > 0){
        throw invalid_argument("Argumento invalido.");
    };
}

void Texto::validar(string entrada){
    // Pode haver qualquer tipo de letra, digito (0-9)
    // Pode haver sinais (.,;?!:-)
    // Sem espacos em sequencia
    // Sem sinais em sequencia
    if (entrada.length() > max_char){
        throw invalid_argument("Argumento invalido.");
    };
    if (entrada.length() < min_char){
        throw invalid_argument("Argumento invalido.");
    };

    for (int i=0; i < entrada.length(); i++){
        string char_atual;
        char_atual = entrada[i];

        // texto inclui letras, digitos e os sinais
        if (is_text(char_atual) != 1){
            throw invalid_argument("Argumento invalido.");
        };

        if ((char_atual == " ") || (is_signal(char_atual))){
            string prox_char;
            prox_char = entrada[i+1];

            if (char_atual == prox_char){
                throw invalid_argument("Argumento invalido.");
            };
        };
    };
};

void Disciplina::validar(string entrada){
    bool nao_achou = true;
    auto possivel_disciplina = possiveis_disc.begin();

    for (int i=0; i < possiveis_disc.size();i+=1){
        if (*possivel_disciplina == entrada){
            nao_achou = false;
        };
        advance(possivel_disciplina, 1);
    };

    if (nao_achou){
        throw invalid_argument("Argumento invalido.");
    };
}
