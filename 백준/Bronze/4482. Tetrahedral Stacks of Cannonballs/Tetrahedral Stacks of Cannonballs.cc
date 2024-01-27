#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

long long int arr[1100];
long long int summ[1100] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int i, n, sum;
	for (i = 1, sum=0; i <= 1000; i++) {
		sum += i;
		arr[i] = sum;
	}
	for (i = 2, summ[1]=arr[1]; i <= 1000; i++) {
		summ[i] = summ[i - 1] + arr[i];
	}
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> sum;
		cout << i << ": " << sum << " " << summ[sum] << "\n";
	}
}