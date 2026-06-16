#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool achar_par(string texto) {

	string ab;

	for(int i = 0; i < texto.length() - 1; i ++) {

		ab = {texto[i], texto[i + 1]};

		if(texto.find(ab, i + 2) != size_t(-1)){
			return true;
		}
	}

	return false;
}

int main () {

	string entrada;
	int n, bonzinhos = 0;
	char a, c;
	bool check1 = false, check2 = false;

	while(cin >> entrada) {

		n = entrada.length();
		check1 = false, check2 = false;

		for(int i = 0; i < n - 2; i++) {

			a = entrada[i];
			c = entrada[i + 2];

			if(a == c) check2 = true;
		}

		if(achar_par(entrada) == true) check1 = true;

		if(check1 == true && check2 == true) bonzinhos ++;
	}

	cout << bonzinhos << endl;

	return 0;
}
