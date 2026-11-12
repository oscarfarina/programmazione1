#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int risultato(char * argv[]){
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);
    switch(argv[3][0]){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': 
        if(b!=0){
            return a/b;
        }else{
            cout << "divisione per 0 impossibile" << endl;
            return -1;
        }
        default: cout<< "operatore nn riconosciuto" << endl;
        return 0;
    }
    
}

int main(int argc, char * argv []){
    if(argc != 4){
        cout << "errore" << endl;
        cout << "utilizzo: " << argv[0] <<"<num1> <num2> <operatore> " << endl;
        exit(1);
    }

    cout << "risultato: " << risultato(argv) << endl;

    return 0;
}