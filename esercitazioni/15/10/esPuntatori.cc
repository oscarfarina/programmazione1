#include <iostream>
using namespace std;
int main () {
	int a = 0;
    int b = 0;
    
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;

    // r --> riferimento ad a
    int &r = a;

    //puntatori a variabili 
    int *pa = &a;
    int *pb = &b;

    //puntatore a puntatore 
    int **ppa = &pa;

    //puntatore a costante
    const int *pca = &a; 


    cout << "inserisci a e b:";
    cin >> a >> b;

    cout << "hai inserito i valori: " << *pa << ", " << *pb << endl;
    cout << "i puntatori pa e pb valgono: " << pa << ", " << pb << endl;
    cout << "valore puntato da pca: " << *pca << endl;
    cout << "valore var puntata dal puntatore al quale punta ppa: "<< **ppa << endl;

    c1 = *pa;
    c2 = **ppa;
    c3 = *pca;
    c4 = r;

    a += 3;
    cout << "a: " << a << endl;

    *pa += 3;
    cout << "*pa: " << *pa << endl;

    **ppa +=3; 
    cout << "**ppa: " << **ppa << endl;

    r += 3;

    a = c1; // nn dpvrebbe cambiare nulla 
    pa = pb; 

    a+=3;
    *pa +=3;
    **ppa += 3;
    r+=3;
    


    return 0;
}
