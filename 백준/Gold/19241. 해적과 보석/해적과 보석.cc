#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<queue>
//#include<deque>
//#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
//#include<functional>

using namespace std;

vector<pair<int, int>> v;


bool cmp(pair<int, int> a, pair<int, int> b) {
	if ((a.first - b.second) == (b.first - a.second)) return a.first > b.first;
	if (max(a.first, a.second) >= max(b.first, b.second)&& min(a.first, a.second) >= min(b.first, b.second)) 
		return 1;
	else if (max(a.first, a.second) < max(b.first, b.second)&& min(a.first, a.second) < min(b.first, b.second)) 
		return 0;
	else {
		return (a.first - b.second) > (b.first - a.second);
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, n, i, j, x, y;
	long long int sum;
	cin >> test;
	while (test--) {
		cin >> n;
		sum = 0;
		for (i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x, y });
		}
		sort(v.begin(), v.end(), cmp);
		for (i = 0; i < n; i++) {
			if(i % 2 == 0) sum += v[i].first;
			else sum -= v[i].second;
		}
		cout << sum << endl;
		v.clear();
	}
}