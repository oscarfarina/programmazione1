#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int * generate_numbers(int length){
    int * array = new int[length];
    for(int i = 0; i < length; i++){
        array[i] = rand() % (100);
    }
    return array;
}

int main(){
    srand(time(NULL));
    int length;
    cout << "inserisci lunghezza array: ";
    cin >> length;

    int *p = generate_numbers(length);

    for(int i = 0; i < length; i++){
        cout << "array["<< i<<"]: " << p[i] << endl;
    }

    delete [] p;
    return 0;
}