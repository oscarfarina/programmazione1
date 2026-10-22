#include <iostream>
using namespace std;

int somma (int n){
    int value = 0;
    if (n==0){
        return value;
    }else{
        value = n%10 + somma(n/10);
    }
    return value;
}

int main (){
    int n;
    int segno = 1;
    cout << "inserisci n:";
    cin >> n;
    if (n < 0){
        n = -n;
        segno = -1;
    }

    cout << "somma: " << somma(n) * segno << endl;
    return 0;
}