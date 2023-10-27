#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int arr[10001] = { 0 };

int main() {
	int a, b, c, d;
	int x = 1;
	for (; x < 10; x++) {
		arr[2 * x] = 1;
	}
	for (; x < 100; x++) {
		arr[x + x / 10 + x % 10] = 1;
	}
	for (; x < 1000; x++) {
		a = x / 100;
		b = (x - a * 100) / 10;
		c = x - a * 100 - b * 10;
		arr[x + a+b+c] = 1;
	}
	for (; x <= 10000; x++) {
		a = x / 1000;
		b = (x - a * 1000) / 100;
		c = (x - a * 1000 - b * 100)/10;
		d = x - a * 1000 - b * 100 - c * 10;
		if (x + a + b + c + d > 10000)
			continue;
		arr[x + a + b + c+d] = 1;
	}
	for (int i=1; i <=10000; i++) {
		if (arr[i] == 0)
			cout << i << endl;
	}
}