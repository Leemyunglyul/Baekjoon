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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i;
	cin >> n;
	string x;
	cin >> x;
	for (i = 0; i < n - 1; i++) {
		if (x[i + 1] == 'J') cout << x[i] << endl;
	}
}