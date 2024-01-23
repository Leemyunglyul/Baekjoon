#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
//#include<stack>
//#include<algorithm>
//#include<functional>

using namespace std;

int arr[1000100] = {0};
long long int sum[1000100] = { 0 };
//long long int sums[1000100] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int i, x, j, n;
	for (i = 2, sum[1]=1; i <= 1000000; i++) {
		sum[i] += i + 1;
		if (arr[i] == 0) {
			x = i * 2;
			while (x <= 1000000) {
				arr[x] = 1;
				sum[x] += i;
				x += i;
			}
		}
		else {
			x = i * 2;
			while (x <= 1000000) {
				sum[x] += i;
				x += i;
			}
		}
	}
	for (i = 2; i <= 1000000; i++) {
		sum[i] += sum[i - 1];
	}	
	int s;
	cin >> n;
	while (n--) {
		cin >> s;
		cout << sum[s] << "\n";
	}
}