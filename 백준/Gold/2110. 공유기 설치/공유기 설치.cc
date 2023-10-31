#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
long long int arr[200002];

int main() {
	long long int i, n, x, mid, pre, num, max;
	cin >> n >> x;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	long long int start = 1;
	long long int end = (arr[n-1]-arr[0])/(x-1);
	max = -1;
	while (start <= end) {
		mid = (start + end) / 2;
		for (i = 1, pre=arr[0], num=1; i < n; i++) {
			if (pre + mid <= arr[i]) {
				num++;
				pre = arr[i];
			}
		}
		if (num >= x) {
			start = mid+1;
			if (mid > max) max = mid;
		}
		else end = mid - 1;
	}
	cout << max;
	return 0;
}