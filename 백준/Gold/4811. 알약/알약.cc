#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;
long long int arr[40] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, x;
	arr[0] = 1;
	arr[1] = 1;
	for (i = 2; i <= 30; i++) {
		for (j = 0; j < i; j++) {
			arr[i] += arr[j] * arr[i-1 - j];
		}
	}
	cin >> n;
	while (1) {
		if (n == 0) return 0;
		else cout << arr[n] << "\n";
		cin >> n;
	}
}