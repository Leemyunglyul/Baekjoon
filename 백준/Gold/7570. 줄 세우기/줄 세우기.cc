#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int arr[1000001];
int cmp[1000002] = {0};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, i, x, sum1, pre;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x;
		arr[x] = i;
	}
	for (i = 1; i < n; i++) {
		if (arr[i] > arr[i + 1]) { cmp[i] = 1; }
	}
	for (i = 1, sum1 = 0, pre=0; i < n; i++) {
		if (i == 1 && cmp[i] == 0) pre++;
		else if (cmp[i - 1] == 0 && cmp[i] == 1) {
			sum1 = max(sum1, pre + 1);
			pre = 0;
		}
		else if (cmp[i] == 0) pre++;
		else;
	}
	sum1 = max(sum1, pre + 1);
	cout << n-sum1;
}