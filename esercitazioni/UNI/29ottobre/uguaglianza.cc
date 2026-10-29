#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generaRandomArray(int a[], int d, int max){
    for(int k = 0; k < d; k++){
        a[k] = rand() % (max+1);
    }
}

void stampaArray (int a[], int d){
    for(int k=0; k<d; k++){
        cout << a[k] << ", ";
    }
    cout << endl;
}

int contaDoppi(int a1[], int a2[], int d){
    int ctr = 0;
    for(int k=0; k<d; k++){
        if(a1[k] == a2[k]){
            ctr+=1;
        }
    }
    return ctr;
}


int main(){
    srand(time(NULL));
    int a1[10];
    int a2[10];

    generaRandomArray(a1, 10, 10);
    generaRandomArray(a2, 10, 10);

    stampaArray(a1, 10);
    stampaArray(a2, 10);

    cout << "elementi contati: " << contaDoppi(a1, a2, 10);




    return 0;
}