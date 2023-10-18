#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	char x;
	cin >> x;
	if (x == 'M') cout << "MatKor";
	else if (x == 'W') cout << "WiCys";
	else if (x == 'C') cout << "CyKor";
	else if (x == 'A') cout << "AlKor";
	else cout << "$clear";
}