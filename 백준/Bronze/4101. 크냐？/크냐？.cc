#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	while (x != 0 || y != 0) {
		if (x > y)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> x >> y;
	}
	
}