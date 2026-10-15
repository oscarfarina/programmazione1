#include <iostream>
using namespace std;

float trovaMax(float, float, float);
float trovaMin(float, float, float);
float differenza(float,float);

int main (){
    float a;
    float b;
    float c;

    cout << "inserisci a: ";
    cin >> a;

    cout << "inserisci b: ";
    cin >> b;

    cout << "inserisci c: ";
    cin >> c;

    cout << "differenza tra max e min: " << differenza(trovaMax(a,b,c), trovaMin(a,b,c)) << endl;


    return 0;
}

float trovaMax(float a, float b, float c){
    float massimo = a;
    if (b > a && b > c){
        massimo = b;
    }else if (c > a && c > b){
        massimo = c;
    }
    return massimo;
}


float trovaMin(float a, float b, float c){
    float minimo = a;
    if (b < a && b < c){
        minimo = b;
    }else if (c < a && c < b){
        minimo = c;
    }
    return minimo;
}

float differenza (float max, float min){
    return max - min;
}