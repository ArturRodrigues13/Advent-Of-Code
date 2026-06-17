#include <iostream>
#include <string>
using namespace std;

int main () {

	string entrada;
	char c;
	int valor_literal = 0, jump = 0;

	while(cin >> entrada) {
		for(int i = 0; i < entrada.length(); i++) {
			if(jump > 0) {
				jump --;
				continue;
			}
			c = entrada[i];
			if(c == '"') {
				valor_literal ++;
			} else if(c == 92) {
				if(entrada[i + 1] == 'x') {
					valor_literal += 5;
					jump = 3;
					continue;
				}
				valor_literal += 4;
				jump = 1;
			} else {
				valor_literal ++;
			}
		}

		valor_literal += 4;
	}

	cout << valor_literal - 6489 << endl;

	return 0;
}
