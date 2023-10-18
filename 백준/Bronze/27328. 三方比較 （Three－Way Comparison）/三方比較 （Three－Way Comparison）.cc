#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	if (x > y)cout << "1";
	else if (x == y) cout << "0";
	else cout << "-1";

}