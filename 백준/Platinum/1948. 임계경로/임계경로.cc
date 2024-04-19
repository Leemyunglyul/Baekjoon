#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m, s, e;
vector<pair<int, int>> edge[10010];
vector<int> pre[10010];
int costt[10010] = { 0 };
int adj[10010] = { 0 };
queue<pair<int, int>> q;
 
void bfs() {
    q.push({ s, 0 });
    while (!q.empty()) {
        int now = q.front().first;
        int d = q.front().second;
        q.pop();

        int i;
        for (i = 0; i < edge[now].size(); i++) {
            int t = edge[now][i].first;
            int cost = edge[now][i].second;
            adj[t]--;
            if (d + cost > costt[t]) {
                pre[t].clear();
                costt[t] = d + cost;
                pre[t].push_back(now);
            }
            else if (d + cost == costt[t]) {
                pre[t].push_back(now);
            }
            if (adj[t] == 0) {
                q.push({ t, costt[t]});
            }
        }
    }
}

int rev_bfs() {
    queue<int> q;
    q.push(e);
    int sum = 0;
    bool visited[10010];
    fill_n(&visited[0], 10010, false);
    visited[e] = true;
    sum += pre[e].size();
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int i;
        for (i = 0; i < pre[x].size(); i++) {
            if (!visited[pre[x][i]]) {
                sum += pre[pre[x][i]].size();
                //cout << pre[x][i] << " " << pre[pre[x][i]].size() << endl;
                visited[pre[x][i]] = true;
                q.push({ pre[x][i] });
            }
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int x, y, d, i, j;
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        edge[x].push_back({ y, d });
        adj[y]++;
    }
    cin >> s >> e;
    bfs();
    cout << costt[e] << endl << rev_bfs();
}