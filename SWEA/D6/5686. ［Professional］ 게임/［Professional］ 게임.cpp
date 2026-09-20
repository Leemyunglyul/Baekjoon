#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

using namespace std;
using ll = long long;

void solve() {
    int n, m, i, j;
    cin >> n >> m;

    vector<vector<int>> arr(n + 2, vector<int>(m + 2, 0));
    vector<vector<array<int, 2>>> sum(
        n + 2, vector<array<int, 2>>(m + 2, {0, 0})
    );
    vector<int> row(n + 2, 0);
    vector<array<int, 2>> dp(n + 2, {0, 0});

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (i = 1; i <= n; i++) {
        sum[i][1][1] = arr[i][1];
        sum[i][2][0] = arr[i][1];
        sum[i][2][1] = arr[i][2];

        for (j = 3; j <= m; j++) {
            sum[i][j][0] = max(sum[i][j - 1][0], sum[i][j - 1][1]);
            sum[i][j][1] = sum[i][j - 1][0] + arr[i][j];
        }

        row[i] = max(sum[i][m][0], sum[i][m][1]);
    }

    dp[1][1] = row[1];
    dp[2][0] = row[1];
    dp[2][1] = row[2];

    for (i = 3; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = row[i] + dp[i - 1][0];
    }

    cout << max(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cout << "#" << tc << " ";
        solve();
    }

    return 0;
}