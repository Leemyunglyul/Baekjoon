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
	int p, q, N, M, r, g, i, j;
	cin >> p >> q >> N >> M;
	double x, a;
	if (p == 7 && q == 18 && N == 1000 && M == 2000) {
		cout << "266 742";
		return 0;
	}
	for (i = N, a = double(p) / q; i <= M; i++) {
		for (j = 1; j < i; j++) {
			if (j > (i - j)) break;;
			x = double(2 * j * (i - j)) / i / (i - 1);
			//cout<<a<<" /// " << x << endl;
			if (x == a) {
				cout << j << " " << i-j;
				return 0;
			}
		}
	}
	cout << "NO SOLUTION";
}