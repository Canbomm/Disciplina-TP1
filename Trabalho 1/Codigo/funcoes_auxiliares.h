#ifndef lista_incluida
#define lista_incluida
#include <list>
#endif

#ifndef funcoes_aux_incluida
#define funcoes_aux_incluida

using namespace std;

// funcao abaixo retirada de: "https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits"
bool is_digits(const string &str){
    return str.find_first_not_of("0123456789") == string::npos;
    };

// funcao abaixo eu que fiz adaptando a funcao de cima
bool is_char_uppercase(const string &str){
    return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos;
};

bool is_char(const string &str){
    return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == string::npos;
};

bool is_signal(const string &str){
    return str.find_first_not_of(".,;?!:-") == string::npos;
};

bool is_text(const string &str){
    return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,;?!:- ") == string::npos;
};

bool tem_repetido(string str)
{
    for (int i = 0; i < str.length()-1; i++){
        for (int j = i + 1; j < str.length(); j++){
            if (str[i] == str[j]) {
                return true;
            };
        };
    };
    return false;
};

#endif
