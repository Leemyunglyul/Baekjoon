#include<iostream>
#include<math.h>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

long long int node[1010][1010] = { 0 };
long long int d[1010] = { 0 };
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>>pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int city, bus, i, j, start, end, x, dis;
	x = 21000000000;
	cin >> city >> bus;
	for (i = 1; i <= city; i++) {
		for (j = 1; j <= city; j++) {
			node[i][j] = x;
		}
		d[i] = x;
		node[i][i] = 0;
	}
	for (i = 0; i < bus; i++) {
		cin >> start >> end >> dis;
		if (node[start][end] > dis) node[start][end] = dis;
	}
	cin >> start >> end;
	pq.push({0, start });
	d[start] = 0;
	while (!pq.empty()) {
		long long int cost = pq.top().first;
		long long int cur = pq.top().second;
		pq.pop();

		for (i = 1; i <=city; i++) {
			long long int next = i;
			long long int ccost = node[cur][next];

			if (d[next] > cost + ccost) {
				d[next] = cost + ccost;
				pq.push({ d[next],next });
			}
		}
	}
	cout << d[end];
}