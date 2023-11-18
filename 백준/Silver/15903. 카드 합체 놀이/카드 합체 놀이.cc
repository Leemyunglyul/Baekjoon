#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
priority_queue <long long int, vector<long long int>, greater<long long int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, i, m, x, sum, y;
	cin >> n >> m;
	for (i = 0, sum=0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
	while (m--) {
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);
		q.push(x + y);
	}
	while (!q.empty()) {
		sum += q.top();
		q.pop();
	}
	cout << sum;
}