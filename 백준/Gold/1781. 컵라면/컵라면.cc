#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

int main() {
	int n, i, x, y, sum;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		pq.push({ x, -y });
	}
	sum = 0;
	while (pq.empty() == 0) {
		if (p.empty() == 1) {
			p.push({ -pq.top().second, pq.top().first});
		}
		else if (p.size() < pq.top().first) {
			p.push({ -pq.top().second, pq.top().first });
		}
		else if (p.top().first < -pq.top().second) {
			p.pop();
			p.push({ -pq.top().second, pq.top().first });
		}
		pq.pop();
	}
	while (p.empty() == 0) {
		sum += p.top().first;
		p.pop();
	}
	cout << sum;
}