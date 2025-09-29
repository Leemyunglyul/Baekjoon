#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue <int, vector<int>, greater<int>> p;

int main() {
	int n, i, x,y;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		pq.push({ x, y });
	}
	while (!pq.empty()) {
		if (p.empty()) {
			p.push(pq.top().second);
		}
		else {
			if (p.top() <= pq.top().first) {
				p.pop();
			}
			p.push(pq.top().second);
		}
		pq.pop();
	}
	cout << p.size();
}