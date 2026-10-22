#include <iostream>
using namespace std;

int sommaPari(int n){
    int value = 0;
    if (n%2 == 1){
        n--;
    }
    if(n == 0){
        return value;
    }else{
        value = n + sommaPari(n-2);
    }
    return value;
}

int main (){
    int n;
    cout << "inserisci n: ";
    cin >> n;

    if(n < 0){
        cout << "numero deve essere positivo";
        exit(1);
    }

    cout << "somma pari: " << sommaPari(n);

    return 0;
}