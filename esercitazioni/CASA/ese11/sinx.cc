#include <iostream> 
#include <cmath>
using namespace std;

int fact(int f){
    int res = 0;
    if(f==1 || f==0){
        res = 1;
    }else{
        res = f * fact(f-1);
    }
    return res;
}

double sinx(double x, int n){
    double result = 0;
    if(n == 0){
        result = x;
    }else{
        result = pow(-1, n) * pow(x, 2*n +1) / fact(2*n+1) + sinx(x, n-1);
    }
    return result;
}

int main(){
    int n;
    float x;
    cout << "inserisci ordine di sviluppo:";
    cin >> n;
    cout << "inserisci x per calcolare sinx:";
    cin >> x;

    cout << "sin(" <<x<<"), n="<<n<< " --> " << sinx(x,n) << endl;


    return 0;
}