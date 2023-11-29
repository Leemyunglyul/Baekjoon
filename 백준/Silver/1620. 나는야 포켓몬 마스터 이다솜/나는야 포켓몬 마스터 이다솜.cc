#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>
#include <map>

using namespace std;
map<string, int> map1;
map<int, string> map2;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, sum;
	cin >> n >> m;
	string x;
	for (i = 1; i <=n; i++) {
		cin >> x;
		map1[x] = i;
		map2[i] = x;
	}
	for (i = 0; i < m; i++) {
		cin >> x;
		if (map1[x]) cout << map1[x] << "\n";
		else cout << map2[stoi(x)] << "\n";
	}
}