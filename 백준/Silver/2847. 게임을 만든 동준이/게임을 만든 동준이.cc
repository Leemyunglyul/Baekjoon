#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
//#include <queue>
//#include <deque>
//#include <algorithm>

using namespace std;
int arr[111];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, sum, j;
	cin >> n;
	for (i = 0;i<n;i++) {
		cin >> arr[i];
	}
	for (i = 1, sum=0; i < n; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] >= arr[j+1]) {
				sum += arr[j] - arr[j+1] + 1;
				arr[j] = arr[j+1] - 1;
			}
		}
	}
	cout << sum;
}