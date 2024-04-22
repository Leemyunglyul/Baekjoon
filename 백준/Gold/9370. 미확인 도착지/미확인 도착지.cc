#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

vector<pair<int, int>> edge[2100];
int dp[2100];
int big = 2100000000;
int dp2[2100];
vector<int> dt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, n, m, t, i, j, x, y, d;
    int s, g, h;
    cin >> testn;
    while (testn--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        dt.clear();
        for (i = 1; i <= 2010; i++) {
            edge[i].clear();
        }
        for (i = 1; i <= m; i++) {
            cin >> x >> y >> d;
            edge[x].push_back({ y, d });
            edge[y].push_back({ x, d });
        }
        for (i = 1; i <= t; i++) {
            cin >> x;
            dt.push_back(x);
        }
        priority_queue<pair<int, int>> pq;
        pq.push({ 0, s });
        fill_n(&dp[0], 2100, big);
        dp[s] = 0;
        while (!pq.empty()) {
            int dis = -pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (dp[idx] != dis) continue;

            for (i = 0; i < edge[idx].size(); i++) {
                int nextt = edge[idx][i].first;
                int costt = edge[idx][i].second;

                if (dp[nextt] > costt + dis) {
                    dp[nextt] = costt + dis;
                    pq.push({ -dp[nextt], nextt });
                }
            }
        }
        int dd;
        if (dp[h] > dp[g]) dd = h;
        else dd = g;
        pq.push({ -dp[dd], dd });
        fill_n(&dp2[0], 2100, big);
        dp2[dd] = dp[dd];
        while (!pq.empty()) {
            int dis = -pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (dp2[idx] != dis) continue;

            for (i = 0; i < edge[idx].size(); i++) {
                int nextt = edge[idx][i].first;
                int costt = edge[idx][i].second;

                if (dp2[nextt] > costt + dis) {
                    dp2[nextt] = costt + dis;
                    //cout << nextt<< "->" << dp2[nextt] << endl;
                    pq.push({ -dp2[nextt], nextt });
                }
            }
        }
        sort(dt.begin(), dt.end());
        for (i = 0; i < dt.size(); i++) {
            //cout << dt[i] << "->" << dp[dt[i]] << "vs" << dp2[dt[i]] << endl;
            if (dp[dt[i]] >= big || dp2[dt[i]] >= big) continue;
            if (dp[dt[i]] == dp2[dt[i]]) {
                cout << dt[i] << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}