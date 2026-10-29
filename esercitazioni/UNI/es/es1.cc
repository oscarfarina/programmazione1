#include <iostream>
using namespace std;
int main () {
	int a = 0;
    int b = 0;
	int valoreAssoluto = 0;
	cout << "inserisci un numero intero a: ";
	cin >> a;

    cout << "inserisci un numero intero b: ";
	cin >> b;

	int valoreAssoluto = (a-b)*((a>b) - (b>a));
	cout << "il risultato è: " << valoreAssoluto << endl;
	return 0;
}
