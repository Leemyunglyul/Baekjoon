#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int n = 5;
	int sum = 0;
	int x;
	while (n--) {
		cin >> x;
		sum += x;
	}
	cout << sum;
}