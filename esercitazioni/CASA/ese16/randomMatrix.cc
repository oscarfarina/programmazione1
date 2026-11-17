#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int ** generate_matrix(int rows, int cols){
    int ** matrix = new (nothrow) int *[rows];
    if(matrix == NULL){
        delete [] matrix;
        exit(1);
    }
    for(int i = 0; i < rows; i++){
        matrix[i] = new (nothrow) int[cols];
        if(matrix[i] == NULL){
            for(int k = 0; k<i; k++){
                delete [] matrix[k];
            }
            delete [] matrix;
            exit(1);
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j=0; j<cols;j++){
            matrix[i][j] = rand() % (100);
        }
    }
    return matrix;
}

int main(int argc, char * argv[]){
    if(argc != 3){
        cout << "errore!!! " << endl;
        exit(1);
    }
    int rows = stoi(argv[1]);
    int cols = stoi(argv[2]);

    srand(time(NULL));
    
    int **p = generate_matrix(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j=0; j<cols;j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<rows;i++){
        delete [] p[i];
    }
    delete [] p;
    return 0;
}