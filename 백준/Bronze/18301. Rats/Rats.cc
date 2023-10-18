#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << floor((double)(x + 1) * (y + 1) / (z + 1) - 1);
}