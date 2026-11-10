#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row = 3;
const int col = 3;


void stampa(int m[row][col]){
    for(int i = 0; i < row; i++){
        for(int k=0; k<col; k++){
            cout << m[i][k] << ", ";
        }
        cout << endl;
    }
}

int calcolaSomma(int m[row][col]){
    int somma = 0;
    for(int i = 0; i < row; i++){
        for(int k = 0; k < col; k++){
            if(k>=i){
                somma += m[i][k];
            }
        }
    }
    return somma;
}


int main(){
    srand(time(NULL));

    int m [row][col];
    for(int i = 0; i < row; i++){
        for(int k=0; k < row; k++){
            m[i][k] = rand() % (10);
        }
    }
    stampa(m);
    cout << "somma: " << calcolaSomma(m) << endl;

    return 0;
}