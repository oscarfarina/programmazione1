#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort (double array [], int length){
    for(int i = 0; i < length-1; i++){
        for(int j = 0; j < length-1; j++){
            if(array[j] < array[j+1]){
                double tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

double * arrayTemperatura(fstream &file, int M){
    double * array = new (nothrow) double[M];
    if(array == NULL){
        delete [] array;
    }
    int i = 0;
    while(i < M && (file >> array[i])){
        i++;
    }
    bubbleSort(array, M);
    return array;
}


int main(int argc, char * argv[]){
    if(argc != 4){
        cout << "errore!!! " << endl;
        cout << "utilizzo: " << argv[0] << " <file> <M> <N>" << endl;
        exit(1);
    }
    int M = stoi(argv[2]);
    int N = stoi(argv[3]);
    if(N > M){
        cout << "numero di confronto maggiore dei nummeri effettivamente presenti" << endl;
        exit(1);
    }

    fstream file;
    file.open(argv[1], ios::in);
    if(file.fail()){
        cout << "errore nell'apertura o file inesistente" << endl;
        file.close();
        exit(1);
    }
    
    double *a = arrayTemperatura(file, M);
    if(a == NULL){
        cout << "errore allocazione memoria" << endl;
        file.close();
        exit(1);
    }
    file.close();

    for(int i = 0; i < N; i++){
        cout << a[i] << endl;
    }
    delete [] a;
    return 0;
}