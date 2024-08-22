#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

long long big = 987654321987654;
long long dp[210][210];
long long stop[210];
vector<tuple<int, int, int>> query;
stack<long long> anw;
int n, m, q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    long long i, j, x, y, w, k, z;
    for (i = 1; i <= n; i++) {
        cin >> stop[i];
    }
    fill_n(&dp[0][0], 210 * 210, big);
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        dp[x][y] = w;
        dp[y][x] = w;
    }
    for (i = 1; i <= q; i++) {
        cin >> x >> y >> z;
        query.push_back({ x, y, z });
        if (x == 1) {
            stop[y] += z;
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            if (k == i) continue;
            for (j = 1; j <= n; j++) {
                if (k == j) continue;
                if (dp[i][j] > dp[i][k] + dp[k][j] + stop[k]) {
                    dp[i][j] = dp[i][k] + dp[k][j] + stop[k];
                }
            }
        }
    }
    for (i = q - 1; i >= 0; i--) {
        x = get<0>(query[i]);
        y = get<1>(query[i]);
        z = get<2>(query[i]);
        if (x == 1) {
            stop[y] -= z;
            for (k = 1; k <= n; k++) {
                if (k == y) continue;
                for (j = 1; j <= n; j++) {
                    if (y == j) continue;
                    if (dp[k][j] > dp[k][y] + dp[y][j] + stop[y]) {
                        dp[k][j] = dp[k][y] + dp[y][j] + stop[y];
                    }
                }
            }
        }
        else {
            if (dp[y][z] == big) anw.push(-1);
            else anw.push(dp[y][z]);
        }
    }
    while (!anw.empty()) {
        cout << anw.top() << "\n";
        anw.pop();
    }
}