#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int row = 5;
const int col = 5;


void stampa(int m[][col], int row){
    for(int i = 0; i < row; i++){
        for(int k=0; k<col; k++){
            cout << m[i][k] << " ";
        }
        cout << endl;
    }
}

int *calcolaPercorso(int m[row][col]){
    int *percorso = new int[col];
    for(int i = 0; i < col; i++) {
        percorso[i] = -1;        
    }                               
    int j = 0;                     
    for(int i = 0; i < row; i++){  
        if(m[i][j] == 1){
            percorso[j] = i;
            j++;               
            for(int k = i-1; k <= i+1; k++){
                if(k >= 0 && k <= row){
                    if(m[k][j] == 1){
                        i = k-1;
                        break;
                    }else{
                        if(k > i){
                            percorso[j-1] = -1;
                            i = percorso[j-2];
                            j--;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(percorso[col - 1] == -1){
        cout << "percorso inesistente!!!" << endl;
        exit(1);
    }
    return percorso;
}

void stampaPercorso(int percorso[], int m[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(percorso[j] == i){
                cout << "*";
            }else{
                cout << "-";
            }
        }
        cout << endl;
    }
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
    int *percorso = calcolaPercorso(m);
    stampaPercorso(percorso, m);


    delete [] percorso;
    return 0;
}