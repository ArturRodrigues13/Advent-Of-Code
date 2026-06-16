#include <iostream>
using namespace std;

int main () {

	int total = 0;
	int l, w, h, lw, wh, lh;

	while (true) {
        while (cin.peek() == ' ' || cin.peek() == '\n')
            cin.ignore(1);
        if (cin.eof()) break;

        cin >> l;
        cin.ignore(1);
        cin >> w;
        cin.ignore(1);
        cin >> h;

		lw = l * w;
		wh = w * h;
		lh = l * h;

		total += 2 * lw + 2 * wh + 2 * lh;

		if(lw <= wh && lw <= lh)
			total += lw;
		else if(wh <= lw && wh <= lh)
			total += wh;
		else
			total += lh;
	}

	cout << total << endl;

	return 0;
}
