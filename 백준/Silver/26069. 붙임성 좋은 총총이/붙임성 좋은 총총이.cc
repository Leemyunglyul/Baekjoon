#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
map<string, int> m1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, sum, start;
	cin >> n;
	string x, y;
	start = 0;
	sum = 0;
	while (n--) {
		cin >> x >> y;
		if (x == "ChongChong") {
			start = 1;
			m1[y] = 1;
			continue;
		}
		else if (y == "ChongChong") {
			start = 1;
			m1[x] = 1;
			continue;
		}
		if (start == 0) continue;
		if (m1.find(x) != m1.end() && m1.find(y) != m1.end()) {
		}
		else if (m1.find(x) != m1.end() && m1.find(y) == m1.end()) {
			m1[y] = 1;
		}
		else if (m1.find(x) == m1.end() && m1.find(y) != m1.end()) {
			m1[x] = 1;
		}
	}
	cout << m1.size() + 1;
}