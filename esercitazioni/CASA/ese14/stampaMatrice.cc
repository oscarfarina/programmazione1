#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row = 3;
const int col = 4;


void stampa(int m[][col], int row){
    for(int i = 0; i < row; i++){
        for(int k=0; k<col; k++){
            cout << m[i][k] << ", ";
        }
        cout << endl;
    }
}


void stampaPuntMatrice(int** m, int row, int col){
    for(int i = 0; i < row; i++){
        for(int k=0; k < col; k++){
            cout << m[i][k] << ", ";
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


    int** am = new int*[row]; 
    for(int i = 0; i < row; i++){
        am[i] = new int[col]; // Alllochiamo le colonne per ogni riga
        for(int k = 0; k < col; k++){
            am[i][k] = rand() % 10;
        }
    }

    stampa(m, col);
    stampaPuntMatrice(am, row, col);

    for(int i = 0; i < row; i++){
        delete[] am[i]; // Libera ogni singola riga
    }
    delete[] am;

    return 0;
}