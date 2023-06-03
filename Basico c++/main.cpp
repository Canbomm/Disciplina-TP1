#include <iostream>
using namespace std;

// Aprendendo entrada e saida
/* int main()
{
    // declarando variaveis
    int valor1;
    int valor2;
    int valor3;

    // pegando entrada
    cout << "Digite um valor: ";
    cin >> valor1;
    cout << "Digite mais um valor: ";
    cin >> valor2;
    cout << "Digite o ultimo valor: ";
    cin >> valor3;

    // montando a saida
    cout << "Valores recebidos: " << valor1 << ", " << valor2 << " e "  << valor3 << "\n";
    cout << "Segundo valor *2: " << valor2*2 << "\n";
    cout << "Terceiro valor repetido 3 vezes: " << valor3 << valor3 << valor3 << "\n";

    return 0;
}
*/

// Aprendendo funcoes, recursividade e loop
int pow(int base, int expoente){
    if (expoente <= 0)
        return 1;

    return base * pow( base, expoente-1);
}

int main(){
    int operacoes;
    cout << "Quantas operacoes de potenciacao gostaria de realizar: ";
    cin >> operacoes;

    while (operacoes > 0){
        int base;
        int expoente;

        cout << "Digite um valor para a base: ";
        cin >> base;
        cout << "Digite um valor para o expoente: ";
        cin >> expoente;

        cout << "Esse foi o resultado: " << pow(base, expoente) << "\n";
        operacoes --;
    }

    // Iterando
    string frase;
    frase = "Eu sou uma frase";
    int tam_frase;
    tam_frase = frase.length();
    while (tam_frase > 0) {
        cout << "Caractere atual: " << frase[tam_frase-1] << "\n";
        tam_frase --;
    }

    return 0;
}
