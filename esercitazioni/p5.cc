#include <iostream>
using namespace std;
int main () {
	int secondi;
	cout << "inserisci il numero di secondi da mezzanotte: ";
	cin >> secondi;
	int h = secondi / 3600 % 24;
	int min = secondi / 60 % 60;
	secondi %= 60;
	cout << "h:min:sec = " << h << ":" << min << ":" << secondi << endl; 
	return 0;
}
