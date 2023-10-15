#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	long long int a, b;
	cin >> a >> b;
	if (a > b) cout << a - b;
	else cout << b - a;
}