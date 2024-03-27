#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[510];//edge
int path[510][510];
int dp[510];//장소 거리
int pre[510];//이전 노드
priority_queue<pair<int, int>> pq;//우선순위 큐
int n, m, s, d;//장소, 길, 시작, 끝
vector<int> rev[510];

void remove(int now, int shortp) {
    int i, j, cur, temp;
    if (now == s) return;

    for (i = 0; i < rev[now].size(); i++) {
        int end_pre = rev[now][i];
        if (path[end_pre][now]!=INT_MAX && dp[end_pre] + path[end_pre][now] == shortp) {
            path[end_pre][now] = INT_MAX;
            remove(end_pre, dp[end_pre]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, x, y, w;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        cin >> s >> d;

        fill_n(&path[0][0], 510 * 510, INT_MAX);
        for (i = 0; i < n; i++) {//초기화
            pre[i] = i;
            dp[i] = INT_MAX;
        }

        for (i = 0; i < m; i++) {//path 입력
            cin >> x >> y >> w;
            edge[x].push_back({ y, w });
            path[x][y] = w;
            rev[y].push_back(x);
        }
        dp[s] = 0;
        pq.push({ 0, s });
        //dijkstra
        while (!pq.empty()) {
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            for (i = 0; i < edge[cur].size(); i++) {
                int next = edge[cur][i].first;
                int ccost = edge[cur][i].second;

                if (dp[next] > cost + ccost) {
                    dp[next] = cost + ccost;
                    pre[next] = cur;
                    pq.push({ dp[next], next });
                }
            }
        }
        for (i = 0; i < rev[d].size(); i++) {
            int end_pre = rev[d][i];
            if (path[end_pre][d] != INT_MAX && dp[end_pre] + path[end_pre][d] == dp[d]) {
                path[end_pre][d] = INT_MAX;
                remove(end_pre, dp[end_pre]);
            }
        }

        fill_n(&dp[0], 510, INT_MAX);
        dp[s] = 0;
        pq.push({ 0, s });
        //dijkstra
        while (!pq.empty()) {
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            for (i = 0; i < edge[cur].size(); i++) {
                int next = edge[cur][i].first;
                int ccost = edge[cur][i].second;
                if (path[cur][next] == INT_MAX) continue;

                if (dp[next] > cost + ccost) {
                    dp[next] = cost + ccost;
                    pre[next] = cur;
                    pq.push({ dp[next], next });
                }
            }
        }
        if (dp[d] == INT_MAX) cout << "-1\n";
        else cout << dp[d] << "\n";

        for (i = 0; i < n; i++) {//초기화
            edge[i].clear();
            rev[i].clear();
        }
    }
}