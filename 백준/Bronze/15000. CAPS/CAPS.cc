#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	string x;
	cin >> x;
	for (int i = 0; i < x.size(); i++) {
		x[i] = toupper(x[i]);
	}
	cout << x;
}