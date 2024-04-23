#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int mat[510][2], n;
long long dp[510][510];
long long big = 987654321987;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int i, s, m, e;
    for (i = 1; i <= n; i++) {
        cin >> mat[i][0] >> mat[i][1];
        
    }
    fill_n(&dp[0][0], 510 * 510, big);
    for (i = 1, dp[n][n]=0; i < n; i++) {
        dp[i][i + 1] = mat[i][0] * mat[i][1] * mat[i + 1][1];
        dp[i][i] = 0;
    }
    for (i = 2; i <= n-1; i++) {
        for (s = 1; s <= n; s++) {//start
            e = s + i;
            if (e > n) break;
            for (m = s; m < e; m++) {//end
                dp[s][e] = min(dp[s][e],
                    dp[s][m]+dp[m+1][e]+mat[s][0]*mat[m][1]*mat[e][1]);
            }
       }
    }
    cout << dp[1][n];

    return 0;
}