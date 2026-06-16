#include <iostream>
#include <string>
using namespace std;

int main () {

	string entrada;
	int floor;
	char c;

	cin >> entrada;

	int n = entrada.length();

	for(int i = 0; i < n; i++) {

		c = entrada[i];
		if(c == '(')
			floor ++;
		else
			floor --;
	}

	cout << floor << endl;
	return 0;
}
