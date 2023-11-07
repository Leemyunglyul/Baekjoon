#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
//#include <cmath>
#include <queue>
//#include <stack>
//#include <algorithm>

using namespace std;
priority_queue <int> p1;
priority_queue <int, vector<int>, greater<int>> p2;

int main() {
	int n, i, x;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while(n--) {
		cin >> x;
		if (p1.empty() == 1) {
			p1.push(x);
		}
		else if (x <= p1.top()) {
			if (p1.size() > p2.size()) {
				p2.push(p1.top());
				p1.pop();
			}
			p1.push(x);
		}
		else if (x > p1.top()) {
			if (p2.empty() == 1) p2.push(x);
			else if (x <= p2.top()) {
				if (p1.size() == p2.size()) p1.push(x);
				else p2.push(x);
			}
			else if (x > p2.top()) {
				if (p1.size() == p2.size()) {
					p1.push(p2.top());
					p2.pop();
				}
				p2.push(x);
			}
		}
		cout << p1.top() << "\n";
	}
	return 0;
}