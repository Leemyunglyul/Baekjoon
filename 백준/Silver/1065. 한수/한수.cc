#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int n, i, sum, x, y, z;
	cin >> n;
	for (i = 1, sum = 0; i <= n; i++) {
		if (i < 100) sum++;
		else {
			x = i / 100;
			y = (i - x * 100)/10;
			z = i % 10;
			if (2 * y == x + z) sum++;
		}
	}
	cout << sum;
}