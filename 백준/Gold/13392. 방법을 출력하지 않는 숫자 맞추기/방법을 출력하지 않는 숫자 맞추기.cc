#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>
#include <queue>

using namespace std;

const int INF = 1e9;
int dp[10010][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string target, current;
    cin >>n>>current>>target;

    fill_n(&dp[0][0], 10010 * 10, INF);
    dp[0][0] = 0;

    for(int i=0;i<n;i++) {
        int cur = current[i] - '0';
        int tar = target[i] - '0';

        for(int L = 0;L<10;L++) {
            if(dp[i][L] == INF) continue;

            int now = (cur + L) % 10;

            int left = (tar - now + 10) % 10;
            int next_L = (L + left) % 10;
            dp[i+1][next_L] = min(dp[i+1][next_L], dp[i][L] + left);

            int right = (now - tar + 10) % 10;
            dp[i+1][L] = min(dp[i+1][L], dp[i][L] + right);
        }
    }

    int res = INF;
    for(int i=0;i<10;i++) {
        res = min(res, dp[n][i]);
    }
    cout << res << "\n";
    return 0;
}