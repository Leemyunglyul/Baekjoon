#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>

using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int>> q;
//vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, i, num, x, y, sum;
	cin >> num;
	while (num--) {
		cin >> n;
		sum = 0;
		for (i = 0; i < n; i++) {
			cin >> x;
			q.push(x);
		}
		while (q.size() > 1) {
			x = q.top();
			q.pop();
			y = q.top();
			q.pop();
			sum += x + y;
			//cout << x+y<<"//";
			q.push(x + y);
		}
		cout << sum <<"\n";
		q.pop();
	}
}