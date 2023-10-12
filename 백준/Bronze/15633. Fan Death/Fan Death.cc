#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int n, sum, i, x;
	cin >> n;
	for (sum = 0, i = 1; i <= n; i++) {
		x = n / i;
		if (i * x == n) {
			sum += i;
		}
	}
	cout << sum * 5 - 24;
}