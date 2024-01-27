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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n;
	cin >> n;
	cout << (n*(n-1)*(n-2)*(n-3)*(n-4))/120;
}