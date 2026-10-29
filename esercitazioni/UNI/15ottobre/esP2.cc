#include <iostream>
#include <cmath>
using namespace std;

float calcolaDistanza(float,float,float,float);

int main (){
    float ax;
    float ay;

    float bx;
    float by;

    cout << "inserisci le coordinate x e y di a:";
    cin >> ax >> ay;

    cout << "inserisci le coordinate x e y di b:";
    cin >> bx >> by;

    cout << "risultato: " << calcolaDistanza(ax,ay,bx,by) << endl;

    return 0;
}

float calcolaDistanza(float ax, float ay, float bx, float by){
    float distanza = sqrt(pow((by - ay),2) + pow((bx - ax),2));
    return distanza;
}