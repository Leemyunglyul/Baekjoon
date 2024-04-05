#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>> edge[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int dp[1010];
int pre[1010];
int big = 98764321;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, xx, s, d, w, i, j, cur, cost, nextt, costt;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> s >> d >> w;
		edge[s].push_back({ d, w });
	}
	cin >> s >> d;
	//일단 다시 돌아오는 것.
	fill_n(&dp[0], 1010, big);
	dp[s] = 0;
	pq.push({ dp[s], s });
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
				pre[nextt] = cur;
				pq.push({ dp[nextt], nextt });
			}
		}
	}
	stack<int> st;
	st.push(d);
	cur = d;
	while (cur != s) {
		cur = pre[cur];
		st.push(cur);
	}
	cout << dp[d] << "\n" << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}