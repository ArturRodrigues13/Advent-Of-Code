#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main () {

	string entrada;
	set<vector<int>> pos;
	pos.insert({0,0});
	int x_at = 0, y_at = 0;
	int n;

	cin >> entrada;
	n = entrada.length();

	for(int i = 0; i < n; i ++) {

		if(entrada[i] == '<') {
			x_at -= 1;
		} else if (entrada[i] == '>') {
			x_at += 1;
		} else if (entrada[i] == 'v') {
			y_at += 1;
		} else {
			y_at -= 1;
		}

		pos.insert({x_at, y_at});
	}

	cout << pos.size() << endl;

	return 0;
}
