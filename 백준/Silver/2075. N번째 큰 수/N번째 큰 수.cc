#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>
#include <map>
//#include <set>

using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
//priority_queue<long long int> pq;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, m, x;
	cin >> n;
	m = n * n;
	while (m--) {
		cin >> x;
		if (pq.size() < n) {
			pq.push(x);
		}
		else {
			if (x > pq.top()) {
				pq.pop();
				pq.push(x);
			}
		}
	}
	cout << pq.top();
}