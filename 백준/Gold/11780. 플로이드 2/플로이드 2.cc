#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;

int dp[110][110];
int nextt[110][110];
int sum[110][110];
int big = 987654321;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, x, y, d, k;
    fill_n(&dp[0][0], 110 * 110, big);
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        if (dp[x][y] > d) {
            dp[x][y] = d;
            nextt[x][y] = y;
            sum[x][y] = 1;
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    nextt[i][j] = nextt[i][k];
                    sum[i][j] = sum[i][k] + sum[k][j];
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dp[i][j] == big || i==j) dp[i][j] = 0;
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dp[i][j] == 0) {
                cout << "0\n";
                continue;
            }
            cout << sum[i][j]+1 << " " << i << " ";
            int now = nextt[i][j];
            while (now != j) {
                cout << now << " ";
                now = nextt[now][j];
            }
            cout << j<<"\n";
        }
        
    }
}