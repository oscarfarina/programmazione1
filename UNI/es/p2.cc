#include <iostream>
using namespace std;
int main () {
	int valore1 = 6 , valore2 = 6;
	int i1 = ++valore1, i1 = valore2++;
	int j1 = ++valore1, j1 = valore2++;
	cout << "valore1=" << valore1 << " " << "valore2=" << valore2 << endl;
	cout << "i1, i2=" << i1 << ", " << i2 << endl;
	cout << "j1, j2=" << j1 << ", " << j2 << endl;
	return 0;
}
