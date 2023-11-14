#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int calender[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
stack <pair<int, int>> st;

int judge(int x, int y) {
	return calender[x] + y;
}

int main() {
	int i, j, n, x, y, w, z;
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> w>> x >> y>>z;
		if (judge(w, x) > 335 || judge(y, z) <= 60) continue;
		pq.push({ judge(w, x), judge(y, z) });
	}
	if (pq.empty() == 1 || pq.top().first>=61) {
		cout << "0";
		return 0;
	}
	while (pq.empty() == 0) {
		//cout << pq.top().first << " " << pq.top().second << endl;
		if (st.empty() == 1) {
			st.push({ pq.top().first, pq.top().second });
			pq.pop();
		}
		else if (pq.top().first > st.top().second) {
			cout << "0";
			return 0;
		}
		else {
			if (st.top().second >= 335) {
				pq.pop();
				continue;
			}
			while (1) {
				x = st.top().first;
				y = st.top().second;
				st.pop();
				if (st.empty()==1) {
					if (pq.top().first <= 60 && pq.top().second > y) {
						st.push({ pq.top().first, pq.top().second });
						pq.pop();
					}
					else {
						st.push({ x, y });
						st.push({ pq.top().first, pq.top().second });
						pq.pop();
					}
					break;
				}
				if (st.top().second >= pq.top().first && pq.top().second>y) {
					continue;
				}
				else {
					st.push({ x, y });
					if (pq.top().second > y) {
						st.push({ pq.top().first, pq.top().second });
					}
					pq.pop();
					break;
				}
			}
		}
		//cout << st.size()<<" " << st.top().first << " " << st.top().second << endl<<endl;
	}
	if (st.top().second <= 334) {
		cout << "0";
		return 0;
	}
	while (st.size()>1) {
		x = st.top().first;
		y = st.top().second;
		st.pop();
		if (st.top().second > 335) continue;
		else {
			st.push({ x,y });
			break;
		}
	}
	cout << st.size();
}