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
	int n, i, sum;
	string x;
	cin >> n;
	sum = 0;
	while (n--) {
		cin >> x;
		if (x == "ENTER") m1.clear();
		else if (m1.find(x) == m1.end()) {
			m1[x] = 1;
			sum++;
		}
	}
	cout << sum;
}