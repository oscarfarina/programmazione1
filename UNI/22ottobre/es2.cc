#include <iostream>
using namespace std;

void stampaBinario(int n){
    if (n==1 || n == 0){
        cout << n;
    }else{
        stampaBinario(n/2);
        cout << (n%2);
    }
}

int main (){
    int n;
    cout << "inserisci n intero: ";
    cin >> n;
    
    if (n < 0){
        cout << "Attenzione! n deve essere positivo";
        exit(1);
    }

    stampaBinario(n);
    return 0;
}