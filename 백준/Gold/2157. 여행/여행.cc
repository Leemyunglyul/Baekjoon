#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int dp[310][310];
int n, m, l;
vector<pair<int, int>> edge[310];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> l;
    int i, j, x, y, d, k;
    for (i = 1; i <= l; i++) {
        cin >> x >> y >> d;
        edge[x].push_back({ y, d });
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < edge[i].size(); j++) {
            int idx = edge[i][j].first;
            int cost = edge[i][j].second;
            for (k = 1; k < m; k++) {
                if (i > 1 && dp[i][k] == 0) continue;
                dp[idx][k + 1] = max(dp[idx][k + 1], dp[i][k] + cost);
            }
        }
    }
    int anw = 0;
    for (k = 2; k <= m; k++) {
        anw = max(dp[n][k], anw);
    }
    cout << anw;

    return 0;
}