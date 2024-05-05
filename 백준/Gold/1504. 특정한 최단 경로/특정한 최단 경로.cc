#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[810];
int dp1[810], dp2[810], dp3[810];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int big = 2000000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, e, i, x, y, d, m1, m2;
    cin >> n >> e;
    fill_n(&dp1[0], 810, big);
    fill_n(&dp2[0], 810, big);
    fill_n(&dp3[0], 810, big);
    for (i = 1; i <= e; i++) {
        cin >> x >> y >> d;
        edge[x].push_back({ y, d });
        edge[y].push_back({ x, d });
    }
    cin >> m1 >> m2;
    
    pq.push({ 0, 1 });
    dp1[1] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (cost != dp1[now]) continue;

        for (i = 0; i < edge[now].size(); i++) {
            int nextt = edge[now][i].first;
            int dis = edge[now][i].second;

            if (cost + dis < dp1[nextt]) {
                dp1[nextt] = cost + dis;
                pq.push({ dp1[nextt] , nextt });
            }
        }
    }
    pq.push({ 0, m1 });
    dp2[m1] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (cost != dp2[now]) continue;

        for (i = 0; i < edge[now].size(); i++) {
            int nextt = edge[now][i].first;
            int dis = edge[now][i].second;

            if (cost + dis < dp2[nextt]) {
                dp2[nextt] = cost + dis;
                pq.push({ dp2[nextt] , nextt });
            }
        }
    }
    pq.push({ 0, m2 });
    dp3[m2] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (cost != dp3[now]) continue;

        for (i = 0; i < edge[now].size(); i++) {
            int nextt = edge[now][i].first;
            int dis = edge[now][i].second;

            if (cost + dis < dp3[nextt]) {
                dp3[nextt] = cost + dis;
                pq.push({ dp3[nextt] , nextt });
            }
        }
    }
    if ((dp1[m1] == big && dp1[m2] == big) || (dp2[n] == big && dp3[n] == big)
        || (dp2[m2] == big && dp3[m1] == big)) cout << "-1";
    else cout << min(dp1[m1] + dp2[m2] + dp3[n], dp1[m2] + dp3[m1] + dp2[n]) << endl;
    //cout << dp1[m1] << " " << dp2[m2] << " " << dp3[n] << " " << dp1[m2]
       // << " " << dp3[m1] << " " << dp2[n];
}