#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row = 3;
const int col = 3;

void stampa(int m[][col], int row){
    for(int i = 0; i < row; i++){
        for(int k=0; k<col; k++){
            cout << m[i][k] << " ";
        }
        cout << endl;
    }
}


int main(){
    srand(time(NULL));

    int m [row][col];
    for(int i = 0; i < row; i++){
        for(int k=0; k < col; k++){
            m[i][k] = rand() % (10);
        }
    }

    stampa(m, row);

    
    return 0;
}