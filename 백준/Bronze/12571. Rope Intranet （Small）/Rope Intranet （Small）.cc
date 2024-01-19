#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

vector <pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, j, x, y, k, num;
	cin >> n;
	for (i = 1 ; i <= n; i++) {
		cin >> m;
		for (j = 1, num = 0; j <= m; j++) {
			cin >> x >> y;
			q.push_back({ x,y });
		}
		for (j = 0; j < m-1; j++) {
			for (k = j + 1; k < m; k++) {
				if (q[j].second > q[k].second && q[j].first < q[k].first) num++;
				else if (q[j].second < q[k].second && q[j].first > q[k].first)num++;
			}
		}
		q.clear();
		cout << "Case #" << i << ": " << num << endl;
	}
}