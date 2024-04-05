#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

vector<pair<int, int>> edge[1010];
vector<pair<int, int>> edge2[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int dp[1010];
int dp2[1010];
int big = 98764321;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, xx, s, d, w, i, j, cur, cost, nextt, costt;
	cin >> n >> m >> xx;
	for (i = 0; i < m; i++) {
		cin >> s >> d >> w;
		edge[s].push_back({ d, w });
		edge2[d].push_back({ s, w });
	}
	//일단 다시 돌아오는 것.
	fill_n(&dp[0], 1010, big);
	dp[xx] = 0;
	pq.push({ dp[xx], xx });
	while (!pq.empty()) {
		cur = pq.top().second;
		cost = pq.top().first;
		pq.pop();
		if (dp[cur] != cost) continue;
		for (i = 0; i < edge[cur].size(); i++) {
			nextt = edge[cur][i].first;
			costt = edge[cur][i].second;
			if (dp[nextt] > cost + costt) {
				dp[nextt] = cost + costt;
				pq.push({ dp[nextt], nextt });
			}
		}
	}
	fill_n(&dp2[0], 1010, big);
	dp2[xx] = 0;
	pq.push({ dp2[xx], xx });
	while (!pq.empty()) {
		cur = pq.top().second;
		cost = pq.top().first;
		pq.pop();
		if (dp2[cur] != cost) continue;
		for (j = 0; j < edge2[cur].size(); j++) {
			nextt = edge2[cur][j].first;
			costt = edge2[cur][j].second;
			if (dp2[nextt] > cost + costt) {
				dp2[nextt] = cost + costt;
				pq.push({ dp2[nextt], nextt });
			}
		}
	}
	for (i = 1, big=0; i <= n; i++) {
		big = max(big, dp2[i] + dp[i]);
	}
	cout << big;
}