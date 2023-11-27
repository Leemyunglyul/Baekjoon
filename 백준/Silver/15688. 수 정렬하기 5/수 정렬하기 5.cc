#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
//#include <queue>
//#include <stack>
#include <algorithm>

using namespace std;
int arr[1000002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}