#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[210][210];
vector<pair<int, int>> edge;
int cost[20010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k, i, j, x, y, w;
    cin >> n >> m;
    fill_n(&dp[0][0], 210 * 210, 987654321);
    for (i = 1; i <= n; i++) dp[i][i] = 0;
    for (i = 1, edge.push_back({0, 0}); i <= m; i++) {
        cin >> x >> y >> w;
        dp[x][y] = min(w, dp[x][y]);
        dp[y][x] = min(w, dp[y][x]);
        edge.push_back({ x,y });
        cost[i] = w;
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i<= n; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    double anw = 987654321;
    double sum;
    for (k = 1; k <= n; k++) {
        for (i = 1, sum=0; i <= m; i++) {
            x = edge[i].first;
            y = edge[i].second;
            sum = max(sum, double(dp[k][x] + dp[k][y] + cost[i]) / 2);
        }
        anw = min(sum, anw);
    }
    cout << fixed;
    cout.precision(1);
    cout << anw;
}