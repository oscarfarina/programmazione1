#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row = 10;
const int col = 10;


void stampa(int m[][col], int row){
    for(int i = 0; i < row; i++){
        for(int k=0; k<col; k++){
            cout << m[i][k] << " ";
        }
        cout << endl;
    }
}

int contaIsole(int m[row][col]){
    int nIsole = 0;
    int n = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(m[i][j] == 1){
                for(int k = i-1; k <= i+1; k++){
                    for(int p = j-1; p <= j+1; p++){
                        if((k >= 0 && p >= 0) && (k < row && p < col)){
                            if(m[k][p] == 1){
                                n++;
                            }
                        }
                    }
                }
                if(n == 1){
                    nIsole ++;
                }
                n = 0;
            }
        }
    }

    return nIsole;
}

int main(){
    srand(time(NULL));

    int m [row][col];
    for(int i = 0; i < row; i++){
        for(int k=0; k < col; k++){
            m[i][k] = rand() % (2);
        }
    }

    stampa(m, row);
    cout << "Le isole contate sono: " << contaIsole(m) << endl;

    
    return 0;
}