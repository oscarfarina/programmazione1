#include <iostream>
using namespace std;

int divisione(int dividendo, int divisore, int& resto){
    int quoziente = 0;
    if (dividendo < divisore){
        resto = dividendo;
    }else {
        quoziente = 1 + divisione(dividendo-divisore, divisore, resto);
    }
    return quoziente;
}

int main(){
    int dividendo, divisore, resto;
    int segno = 1;
    cout << "inserisci dividendo: ";
    cin >> dividendo;

    cout << "inserisci divisore: ";
    cin >> divisore;

    if(divisore == 0){
        cout << "Attenzione! divisione per 0";
        exit(1);
    }

    if (dividendo < 0 && divisore > 0){
        dividendo = -dividendo;
        segno = -1;
    }else if (dividendo > 0 && divisore < 0){
        divisore = -divisore;
        segno = -1;
    }else if (dividendo < 0 && divisore < 0){
        dividendo = -dividendo;
        divisore = -divisore;
    }

    int quoziente = divisione(dividendo, divisore, resto);
    cout << "quoziente: " << quoziente * segno << endl;
    cout << "resto: " << resto;
    return 0;
}
