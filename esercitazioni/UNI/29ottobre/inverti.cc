#include <iostream>
#include <cstdlib>
using namespace std;

void generaRandom(int a[], int d){
    for(int k=0; k<d;k++){
        a[k] = rand() % (10);
    }
}

void stampaArray(int a[], int d){
    for(int k=0;k<d;k++){
        cout << a[k] << ",";
    }
    cout << endl;
}

void inverti(int a[], int d){
    int b;
    for(int i = 0; i < d/2; i++){
        b=a[i];
        a[i] = a[d-i-1];
        a[d-i-1] = b;
    }
}


int main(){
    srand(time(NULL));
    int a[10];

    generaRandom(a, 10);
    stampaArray(a,10);
    inverti(a,10);
    stampaArray(a,10);



    return 0;
}