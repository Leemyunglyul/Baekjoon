#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int arr[10001] = {0};
int a[100001] = { 0 };

int main() {
	int i;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	a[4] = 1;
	a[5] = 1;
	a[6] = 2;
	for (i = 7; i <= 10000; i++) {
		a[i] = a[i - 6] + 1;
	}
	for (i = 4; i <= 10000; i++) {
		arr[i] = arr[i - 1]+a[i];
	}
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		cout << arr[x]<<endl;
	}
	return 0;
}