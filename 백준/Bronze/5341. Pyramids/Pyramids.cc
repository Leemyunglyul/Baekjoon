#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int n, i, sum;
	cin >> n;
	while (n != 0) {
		for (i = 1, sum = 0; i <= n; i++)
			sum += i;
		cout << sum<<endl;
		cin >> n;
	}
}