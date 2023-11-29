#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>
#include <map>

using namespace std;
map<string, int> maps;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, sum;
	cin >> n >> m;
	string x;
	for (i = 0; i < n; i++) {
		cin >> x;
		maps[x] = 1;
	}
	for (i = 0, sum = 0; i < m; i++) {
		cin >> x;
		if (maps[x] == 1) sum++;
	}
	cout << sum;
}