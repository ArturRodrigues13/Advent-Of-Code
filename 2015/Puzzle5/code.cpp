#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main () {

	string entrada, ab;
	int n, v_count = 0, bonzinhos = 0;
	char a, b;
	vector<char> vogais = {'a', 'e', 'i', 'o', 'u'};
	bool check1 = false, check2 = false, check3 = false;

	while(cin >> entrada) {

		n = entrada.length();

		check1 = false, check2 = false, check3 = false, v_count = 0;

		for(int i = 0; i < n - 1; i++) {

			a = entrada[i];
			b = entrada[i + 1];
			ab = {a, b};

			if(v_count < 3)
				if(find(vogais.begin(), vogais.end(), a) != vogais.end()) v_count += 1;

			if(a == b) check2 = true;

			if(ab == "ab" || ab == "cd" || ab == "pq" || ab == "xy") {
				check3 = true;
				break;
			}
		}

		if(find(vogais.begin(), vogais.end(), entrada[n - 1]) != vogais.end()) v_count ++;

		if(v_count > 2) check1 = true;

		if(check1 == true && check2 == true && check3 == false) bonzinhos ++;
	}

	cout << bonzinhos << endl;

	return 0;
}
