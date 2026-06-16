#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void skipWS() {
    while (true) {
        char c = cin.peek();
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r') break;
        cin.ignore(1);
    }
}

void skipString(const char* str) {

	skipWS();
    for (int i = 0; str[i] != '\0'; i++) {
        if (cin.peek() != str[i]) {
            cout << "erro" << "it: " << i << " " << (char) cin.peek() << " " << cin.peek() << endl;
			exit(1);
        }
        cin.ignore(1);
    }
	skipWS();
}

int main () {

	string entrada, op;
	vector<vector<int>> matriz(1000, vector<int>(1000, 0));
	int x1, y1, x2, y2, count = 0;

	while (true) {

		skipWS();
		if(cin.eof()) break;

		cin >> entrada;

		if(entrada == "turn") {
			cin >> op;
		} else {
			op = entrada;
		}

		cin >> x1;
		cin.ignore(1);
		cin >> y1;

		skipString("through");

		cin >> x2;
		cin.ignore(1);
		cin >> y2;

		if(op == "on") {
			for(int i = x1; i <= x2; i++) {
				for(int j = y1; j <= y2; j++) {

					matriz[i][j] += 1;
				}
			}
		} else if(op == "off") {
			for(int i = x1; i <= x2; i++) {
				for(int j = y1; j <= y2; j++) {

					matriz[i][j] = matriz[i][j] > 0 ? matriz[i][j] - 1 : matriz[i][j];
				}
			}
		} else {
			for(int i = x1; i <= x2; i++) {
				for(int j = y1; j <= y2; j++) {

					matriz[i][j] += 2;
				}
			}
		}
	}

	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			count += matriz[i][j];
		}
	}

	cout << count << endl;

	return 0;
}
