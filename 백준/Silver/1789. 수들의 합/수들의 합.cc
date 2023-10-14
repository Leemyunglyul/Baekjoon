#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	long long int n, m, i;
	cin >> n;
	for (m=0, i=1; m <=n;i++) {
		m += i;
	}
	cout << i-2;
}