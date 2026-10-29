#include <iostream>
using namespace std;
int main () {
	char carattere;
	cout << "inserisci un carattere in minuscolo: ";
	cin >> carattere;
	carattere -= ('a' - 'A');
	cout << "il carattere maiuscolo è: " << carattere << endl;


	char carattere2;
	cout << "inserisci un carattere maiuscolo: ";
	cin >> carattere2;
	carattere2 += ('a' - 'A');
	cout << "il carattere minuscolo è: " << carattere2 << endl;
	return 0;
}
