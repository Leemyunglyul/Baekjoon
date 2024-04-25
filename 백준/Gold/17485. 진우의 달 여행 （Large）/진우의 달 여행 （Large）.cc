#include <iostream>
#include <cmath>

using namespace std;

int arr[1010][1010];
int dp[1010][1010][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, k, l;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int anw = 987654321;
    fill_n(&dp[0][0][0], 1010 * 1010 * 3, anw);
    int move[3] = { -1, 0, 1 };
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 1) {
                dp[1][j][0] = arr[1][j];
                dp[1][j][1] = arr[1][j];
                dp[1][j][2] = arr[1][j];
                continue;
            }
            for (k = 0; k <= 2; k++) {
                int idx = j + move[k];
                if (idx<1 || idx>m) continue;
                for (l = 0; l <= 2; l++) {
                    if (k == l) continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][idx][l]+arr[i][j]);
                }
            }
        }
    }
    
    for (j = 1; j <= m; j++) {
        for (k = 0; k <= 2; k++) {
            anw = min(anw, dp[n][j][k]);
        }
    }
    cout << anw;

    return 0;
}