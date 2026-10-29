#include <iostream>
using namespace std;

int MCDTailRecursive(int a, int b){
    if(b == 0){
        return a;
    }else{
        return MCDTailRecursive(b, a%b);
    }
}

int MCDIterativo(int a, int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int a,b;
    cout << "inserisci due numeri per calcolare MCD: ";
    cin >> a >> b;

    if(a > b && b >=  0){
        cout << "MCDTR: " << MCDTailRecursive(a,b) << endl;
        cout << "MCDI: " << MCDIterativo(a,b) << endl;
    }else{
        cout << "errore" << endl;
    }
    return 0;
}