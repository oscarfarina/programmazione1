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

double calcolaMedia(int a[], int d, int &min, int &max){
    double media = 0;
    min = a[0];
    max = a[0];
    for(int k=0;k<d;k++){
        media += a[k];
        if (a[k] > max){
            max = a[k];
        }else if (a[k] < min){            
            min = a[k];
        }
    }
    return media/d;
}



int main(){
    srand(time(NULL));
    int a[10];

    int max;
    int min;
    generaRandom(a, 10);
    stampaArray(a,10);

    cout << "media: "  << calcolaMedia(a, 10, min, max) << endl; 
    cout << "max:" << max << endl;
    cout << "min:" << min << endl; 
    

    return 0;
}