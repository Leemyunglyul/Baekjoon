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
map<string, int, less<>> map1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, sum;
	cin >> n >> m;
	string x;
	for (i = 1; i <=n; i++) {
		cin >> x;
		map1[x] = 0;
	}
	for (i = 0, sum=0; i < m; i++) {
		cin >> x;
		if (map1.find(x) != map1.end()) { map1[x] = 1; sum++; }
	}
	cout << sum << "\n";
	for (auto iter = map1.begin(); iter != map1.end(); iter++) {
		if(iter->second==1) cout << iter->first << "\n";
	}
}