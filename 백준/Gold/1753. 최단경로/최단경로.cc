#include<iostream>
#include<math.h>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> node[20010];
int d[20010] = { 0 };
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>>pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int city, bus, i, j, start, end, x, dis, dt;
	x = 2100000000;
	cin >> city >> bus;
	for (i = 1; i <= city; i++) {
		d[i] = x;
	}
	cin >> dt;
	for (i = 0; i < bus; i++) {
		cin >> start >> end >> dis;
		node[start].push_back({ dis, end });
	}
	pq.push({0, dt });
	d[dt] = 0;
	while (!pq.empty()) {
		long long int cost = pq.top().first;
		long long int cur = pq.top().second;
		pq.pop();

		for (i = 0;i<node[cur].size() ; i++) {
			long long int next = node[cur][i].second;
			long long int ccost = node[cur][i].first;

			if (d[next] > cost + ccost) {
				d[next] = cost + ccost;
				pq.push({ d[next],next });
			}
		}
	}
	for (i = 1; i <= city; i++) {
		if (d[i] == x) cout << "INF";
		else cout << d[i];
		cout << "\n";
	}
}