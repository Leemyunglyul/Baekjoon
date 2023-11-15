#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
priority_queue<pair<long long int, long long int>, 
	vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
long long int sum=0;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	long long int n, x, y, i, start, end;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		pq.push({ x, y });
	}
	for (i = 0, start= pq.top().first, end=pq.top().first; i < n; i++) {
		if (pq.top().first <= end) {
			if (pq.top().second > end) end = pq.top().second;
			pq.pop();
		}
		else {
			sum += end - start;
			start = pq.top().first;
			end = pq.top().second;
			pq.pop();
		}
	}
	sum += end - start;

	cout << sum;
}