#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row = 10;
const int col = 10;


void stampa(float m[row][col]){
    for(int i = 0; i < row; i++){
        for(int k=0; k<col; k++){
            cout << m[i][k] << ", ";
        }
        cout << endl;
    }
}

void filtro(float A[row][col]){
    float B[row][col];
    for(int i = 0; i < row; i++){
        for(int k = 0; k < col; k++){
            if (i+1 > )
            B[i][k] = (A[i - 1][k] + A[i][k - 1] + A[i + 1][k] + A[i][k + 1])/4;
            
        }
    }
    stampa(B);
}


int main(){
    srand(time(NULL));

    float A [row][col];
    for(int i = 0; i < row; i++){
        for(int k=0; k < row; k++){
            A[i][k] = rand() % (10);
        }
    }
    stampa(A);
    cout << endl << endl;
    filtro(A);

    return 0;
}