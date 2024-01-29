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
long long int arr[1600][3];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i;
	cin >> n;
	arr[1][0] = 0;
	arr[1][1] = 1;
	arr[1][2] = 0;
	for (i = 2; i <= n; i++) {
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1])% 1000000007;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2])%1000000007;
		arr[i][0] = (arr[i - 1][1] + arr[i - 1][2])% 1000000007;
	}
	cout<< arr[n][2]%1000000007;
}