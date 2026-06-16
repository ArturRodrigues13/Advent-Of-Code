#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main () {

	string entrada;
	set<vector<int>> posicoes;
	int x_ats = 0, y_ats = 0, x_atr = 0, y_atr = 0;
	int n;

	cin >> entrada;
	n = entrada.length();

	for(int i = 0; i < n; i ++) {

		if(i % 2 == 0) {

			if(entrada[i] == '<') {
				x_ats -= 1;
			} else if (entrada[i] == '>') {
				x_ats += 1;
			} else if (entrada[i] == 'v') {
				y_ats += 1;
			} else {
				y_ats -= 1;
			}

			posicoes.insert({x_ats, y_ats});

		} else {

			if(entrada[i] == '<') {
				x_atr -= 1;
			} else if (entrada[i] == '>') {
				x_atr += 1;
			} else if (entrada[i] == 'v') {
				y_atr += 1;
			} else {
				y_atr -= 1;
			}

			posicoes.insert({x_atr, y_atr});
		}
	}

	cout << posicoes.size() << endl;

	return 0;
}
