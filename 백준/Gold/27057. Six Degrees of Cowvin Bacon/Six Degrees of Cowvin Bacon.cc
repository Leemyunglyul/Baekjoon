#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>

using namespace std;

long long int dp[310][310];
int arr[310];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k, i, j, l, x, y;
    fill_n(&dp[0][0], 310 * 310, INT_MAX);
    cin >> n >> m;
    for (i = 1; i <= n; i++) dp[i][i] = 0;
    while (m--) {
        cin >> l;
        for (i = 1; i <= l; i++) cin >> arr[i];
        for (i = 1; i <= l; i++) {
            for (j = i + 1; j <= l; j++) {
                dp[arr[i]][arr[j]] =dp[arr[j]][arr[i]] = 1;
           }
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i<= n; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int sum = 100000000;
    for (i = 1; i <= n; i++) {
        int temp = 0;
        for (j = 1; j <= n; j++) {
            if (i == j) continue;
            temp += dp[i][j];
        }
        temp =100*temp/(n - 1);
        sum = min(sum, temp);
    }
    cout << sum;
}