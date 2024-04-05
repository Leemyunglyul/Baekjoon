#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int pre[300100];
vector<tuple<int, int, int>> edge[300010];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
long long dp[300010];
pair<long long, long long> path[500010];
long long big = 7654321987654321;
long long small = 500100;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m, i, j, s, d, w, cur, cost, nextt, costt, num, sum, x;
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> s >> d >> w;
		edge[s].push_back({ d, w, i });
		edge[d].push_back({ s,2 * w, i });
		path[i].first = s;
		path[i].second = d;
	}
	fill_n(&dp[0], 300010, big);
	dp[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		cur = pq.top().second;
		cost = pq.top().first;
		pq.pop();
		if (dp[cur] != cost) continue;

		for (i = 0; i < edge[cur].size(); i++) {
			nextt = get<0>(edge[cur][i]);
			costt = get<1>(edge[cur][i]);
			num = get<2>(edge[cur][i]);

			if (dp[nextt] > cost + costt) {
				pre[nextt] = cur;
				dp[nextt] = cost + costt;
				//cout << nextt << "->"<<cost<<"+"<<costt<<"=" << dp[nextt] << endl;
				pq.push({ dp[nextt], nextt });
			}
		}
	}
	for (i = 2, sum = 0; i <= n; i++) {
		sum += dp[i];
		//cout << i << "->" << dp[i]<<"우선순위 "<<pre[i] << endl;
	}
	cout << sum << "\n";
	for (i = 1; i <= m; i++) {
		if (pre[path[i].first] == path[i].second) cout << "0 ";
		else cout << "1 ";
	}
}