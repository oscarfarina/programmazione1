#include <iostream>
using namespace std;
int main () {
	int a = 0;
    int b = 0;
	cout << "inserisci un numero intero a: ";
	cin >> a;
    cout << "inserisci un numero intero b: ";
	cin >> b;

    int max = a * (a>b);
    max += b * (max==0); 

    int min = b * (b<a);
    min += a * (min==0);
	
	cout << "max: " << max << endl;
    cout << "min: " << min << endl;

	return 0;
}
