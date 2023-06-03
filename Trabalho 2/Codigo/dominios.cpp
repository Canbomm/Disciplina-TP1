#include "dominios.h"

using namespace std;

void Codigo::validar(string entrada){
    // Formato: DDDDDDDDDDX
    // D e X = digito de 0 a 9
    int tam_entrada = entrada.length();

    if (tam_entrada != tam_codigo){
        throw invalid_argument("Argumento invalido.");
    };

    if (verificarCharacteres(digitos_validos, entrada) == 0){
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

    cout << "Validando data" << endl;
    cout << dia_str << endl;
    cout << mes_str << endl;
    cout << ano_str << endl;

    if (verificarCharacteres(digitos_validos, dia_str) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
    if (verificarCharacteres(digitos_validos, mes_str) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
    if (verificarCharacteres(digitos_validos, ano_str) == 0){
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

    int max_dias_mes_atual = maiores_dias_do_mes[mes-1];

    if (mes == 2){
        // verificando se o ano e bissexto, ja que o mes e fevereiro
        if ((ano % 4) == 0){
            // como e bissexto e o mes e fevereiro, o limite de dias aumenta em 1
            if ((dia-1 > max_dias_mes_atual) || (dia < menor_dia)){
                throw invalid_argument("Argumento invalido.");
            };
        }
        else{
            // como o ano nao e bissexto, faco a verificacao normal
            if ((dia > max_dias_mes_atual) || (dia < menor_dia)){
                throw invalid_argument("Argumento invalido.");
            };
        };
    }
    else {
        // se nao e fevereiro, nao faz diferenca ser bissexto ou nao
        if ((dia > max_dias_mes_atual) || (dia < menor_dia)){
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

    string caracteres = entrada.substr(0,4);
    string digitos = entrada.substr(4,4);

    if (verificarCharacteres(letras_maiusculas_validas, caracteres) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
    if (verificarCharacteres(digitos_validos, digitos) == 0){
	    throw invalid_argument("Argumento invalido.");
    };
};

void Nome::validar(string entrada){
    // No max 3 nomes
    // No max 20 caracteres
    // Caractere = letra de A a Z (minusculo tambem) e espaco
    // Primeira letra obrigatoriamente maiscula
    // Nao pode ter espaco seguido
    int tam_entrada = entrada.length();
    if (tam_entrada > max_char){
        cout << "Muito grande" << endl;
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
            if (verificarCharacteres(digitos_validos, char_atual)){
                throw invalid_argument("Argumento invalido.");
            };

            if (primeira_letra){
                if (verificarCharacteres(letras_maiusculas_validas, char_atual) != 1){
                    throw invalid_argument("Argumento invalido.");
                };
            }
            else if (verificarCharacteres(letras_validas, char_atual) != 1){
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

bool Senha::tem_repetido(string str){
    for (int i = 0; i < str.length()-1; i++){
        for (int j = i + 1; j < str.length(); j++){
            if (str[i] == str[j]) {
                return true;
            };
        };
    };
    return false;
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

        if (verificarCharacteres(digitos_validos, char_atual)){
            if (min_dig > 0){
                min_dig -= 1;
            };
        }
        else if (verificarCharacteres(letras_maiusculas_validas, char_atual)){
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
        if (verificarCharacteres(char_texto_validos, char_atual) != 1){
            throw invalid_argument("Argumento invalido.");
        };

        if ((char_atual == " ") || (verificarCharacteres(sinais_validos, char_atual))){
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
    string possivel_disciplina;

    for (int i=0; i < quant_disc;i+=1){
        possivel_disciplina = possiveis_disc[i];
        if (possivel_disciplina == entrada){
            nao_achou = false;
        };
    };

    if (nao_achou){
        throw invalid_argument("Argumento invalido.");
    };
}
