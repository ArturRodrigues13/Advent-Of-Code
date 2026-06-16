#include <iostream>
using namespace std;

int main () {

	int total = 0;
	int l, w, h;

	while (true) {

        if (cin.eof()) break;

        cin >> l;
        cin.ignore(1);
        cin >> w;
        cin.ignore(1);
        cin >> h;

		total += l * w * h;

		if(l <= w && h <= w)
			total += 2 * l + 2 * h;
		else if(w <= l && h <= l)
			total += 2 * w + 2 * h;
		else
			total += 2 * l + 2 * w;
	}

	cout << total << endl;

	return 0;
}
