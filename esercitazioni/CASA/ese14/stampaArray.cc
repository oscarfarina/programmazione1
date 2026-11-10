#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void stampa(int * m, int dim){
    for(int i = 0; i < dim; i ++){
        cout << *(m+i) << endl;
    }
}

int main(){
    srand(time(NULL));

    int m [10];
    for(int i = 0; i < 10; i++){
        *(m+i) = rand() % (10);
    }

    stampa(m, 10);

    return 0;
}