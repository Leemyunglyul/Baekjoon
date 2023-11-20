#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <deque>
//#include <algorithm>

using namespace std;

int arr[54];
deque<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, x, num, sum;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < n; i++) {
		q.push_back(i + 1);
	}
	for (i = 0, sum=0; i < m; i++) {
		num = 0;
		while (q.front() != arr[i]) {
			x = q.front();
			q.pop_front();
			q.push_back(x);
			num++;
		}
		sum += min(num, (int)q.size() - num);
		q.pop_front();
	}
	cout << sum;
}