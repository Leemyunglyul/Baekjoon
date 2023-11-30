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
vector<pair<int, string>> v;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
	if (a.first == b.first) {
		if (a.second.size() == b.second.size()) {
			return a.second < b.second;
		}
		else return a.second.size() > b.second.size();
	}
	else return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, sum, m;
	cin >> n>>m;
	string x;
	while (n--) {
		cin >> x;
		if (x.size() < m) continue;
		if (m1.find(x) == m1.end()) {
			m1[x] = 1;
		}
		else {
			m1[x]++;
		}
	}
	for (auto iter = m1.begin(); iter != m1.end(); iter++) {
		v.push_back({ iter->second, iter->first });
	}
	sort(v.begin(), v.end(), cmp);
	for (i = 0; i < v.size(); i++) {
		cout << v[i].second << "\n";
	}
}