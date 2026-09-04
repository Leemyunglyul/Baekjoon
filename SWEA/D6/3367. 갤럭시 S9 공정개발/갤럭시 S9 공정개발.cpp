#include <iostream>
#include <climits>
using namespace std;

const int MAXN = 3005;

int  arr[MAXN];
long long sum[MAXN];
long long dp[MAXN][MAXN];
int  opt[MAXN][MAXN];   // Knuth optimization: 최적 분할 지점

int n;

long long solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + arr[i];

    for (int i = 1; i <= n; i++) {
        dp[i][i]  = 0; 
        opt[i][i] = i;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            int lo = opt[i][j-1];
            int hi = min(j - 1, opt[i+1][j]);
            for (int k = lo; k <= hi; k++) {
                long long v = dp[i][k] + dp[k+1][j];
                if (v < dp[i][j]) {
                    dp[i][j]  = v;
                    opt[i][j] = k;
                }
            }
            dp[i][j] += sum[j] - sum[i-1];
        }
    }
    return dp[1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "#" << tc << " " << solve() << '\n';
    }
    return 0;
}
