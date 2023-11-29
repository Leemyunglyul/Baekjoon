#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>
//#include <map>
#include <set>

using namespace std;
set<int> s1;
set<int> s2;
set<int> s3;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, big, i, x;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> x;
		s1.insert(x);
	}
	for (i = 0; i < m; i++) {
		cin >> x;
		s2.insert(x);
	}
	for (auto iter=s1.begin(); iter!=s1.end(); iter++) {
		if (s2.find(*iter) != s2.end()) {
			s3.insert(*iter);
			s2.erase(s2.find(*iter));
		}
	}
	cout << s1.size() + s2.size()-s3.size() << endl;
}