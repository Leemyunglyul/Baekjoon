#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;


int main() {
	int n, i;
	cin >> n;
	int x, y, z, a, b, c;
	for (i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		cout << "Scenario #" << i << ":" << endl;
		if (z >= x && z >= y) {
			c = z;
			a = x;
			b = y;
		}
		else if (y >= x && y >= z) {
			c = y;
			a = x;
			b = z;
		}
		else {
			c = x;
			a = y;
			b = z;
		}
		if (c * c == b * b + a * a) {
			cout << "yes" << endl << endl;
		}
		else
			cout << "no" << endl << endl;
	}
}