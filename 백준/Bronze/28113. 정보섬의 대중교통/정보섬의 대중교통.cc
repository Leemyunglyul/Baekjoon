#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b < c) {
		cout << "Bus";
	}
	else if (b > c) {
		if (a > b) cout << "Bus";
		else cout << "Subway";
	}
	else cout << "Anything";
}