#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort (int array [], int length){
    for(int i = 0; i < length-1; i++){
        for(int j = 0; j < length-1; j++){
            if(array[j] > array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

int * generate_numbers(int length){
    int * array = new int[length];
    for(int i = 0; i < length; i++){
        array[i] = rand() % (100);
    }
    bubbleSort(array, length);
    return array;
}

int * append(int arrayA[], int arrayB[], int lengthA, int lengthB){
    int * array = new (nothrow) int[lengthA + lengthB];
    if(array == NULL){
        delete [] array;
        exit(1);
    }
    int a = 0;
    int b = 0;
    for(int i = 0; i < lengthA + lengthB; i++){
        if(a < lengthA && (b >= lengthB || arrayA[a] < arrayB[b])){
            array[i] = arrayA[a];
            a++;
        }else{
            array[i] = arrayB[b];
            b++;
        }
    }
    return array;
}


int main(){
    srand(time(NULL));
    int lengthA;
    int lengthB;
    cout << "inserisci lunghezza array: ";
    cin >> lengthA;
    cout << "inserisci lunghezza secondo array: ";
    cin >> lengthB;

    int *arrayA = generate_numbers(lengthA);
    int *arrayB = generate_numbers(lengthB);
    int * concatenato = append(arrayA, arrayB, lengthA, lengthB);

    cout << "arrayA: "; 
    for(int i = 0; i < lengthA; i++){
        cout << arrayA[i] << " ";
    }
    cout << endl;
    cout << "arrayB: "; 
    for(int i = 0; i < lengthB; i++){
        cout << arrayB[i] << " ";
    }
    cout << endl;
    cout << "concatenato: "; 
    for(int i = 0; i < lengthA+lengthB; i++){
        cout << concatenato[i] << " ";
    }
    cout << endl;


    delete [] arrayA;
    delete [] arrayB;
    delete [] concatenato;
    return 0;
}