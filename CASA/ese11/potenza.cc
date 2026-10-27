#include <iostream>
using namespace std;

float potenza(int m, int n){
    float result = 0.0f;
    if(n == 0){
        result = 1.0f;
    }else if(n < 0){
        result = (1.0f/m) * potenza(m, n+1); 
    }else{
        result = m * potenza(m, n-1);
    }
    return result;
}

float potenzaTailRecursive(int m, int n, int acc = 1.0f){
    if(n == 0){
        return acc;
    }else if(n < 0){
        return potenzaTailRecursive(m, n+1, acc * (1.0f/m)); 
    }else{
        return potenzaTailRecursive(m, n-1, acc*m);
    }
}

int main(){
    char continua;

    do {
        int m, n;
        cout << "inserisci m: ";
        cin >> m;
        cout << "inserisci n: ";
        cin >> n;

        cout << "potenza m^n: " << m <<"^"<< n <<" = "<< potenza(m,n) << endl;
        cout << "potenza TAIL RECURSIVE m^n: " << m <<"^"<< n <<" = "<< potenza(m,n) << endl;

        cout << "vuoi farne un altro? s/n";
        cin >> continua;

    }while (continua == 's');

    return 0;
}