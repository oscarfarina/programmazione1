#include <iostream>
#include <cstdlib>
using namespace std;

int intervallo(int a[], int d, int x, int y){
    int value = -1;
    if (x < y){
        value = 0;
        for(int i = 0; i < x; i++){
            value+=1;
            a[i] = 0;
        }
        
        for(int i = y; i < d; i++){
            value+=1;
            a[i] = 0;
        }
    }
    return value;
}

void stampaArray(int a[], int d){
    for(int k=0;k<d;k++){
        cout << a[k] << ",";
    }
    cout << endl;
}


int main(){
    srand(time(NULL));
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int x = 3;
    int y = 5;


    cout << "elementi contati: " << intervallo(a, 10, x, y) << endl;
    stampaArray(a, 10);
    
    return 0;
}