#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

long long big = 187654321987654321;
long long dp[210][210];
long long stop[210];
vector<tuple<long long, long long, long long>> query;
stack<long long> anw;
int n, m, q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    long long i, j, x, y, w, k, z, pre;
    fill_n(&dp[0][0], 210 * 210, big);
    for (i = 1; i <= n; i++) {
        cin >> stop[i];
        dp[i][i] = 0;
    }
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        dp[x][y] = min(w, dp[x][y]);
        dp[y][x] = min(w, dp[y][x]);
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
            for (j = 1; j <= n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j] + stop[k]) {
                    dp[i][j] = dp[i][k] + dp[k][j] + stop[k];
                }
            }
        }
    }
    for (i = query.size()-1, pre=0; i >= 0; i--) {
        x = get<0>(query[i]);
        y = get<1>(query[i]);
        z = get<2>(query[i]);
        if (x == 1) {
            stop[y] -= z;
            if(pre==0|| pre==y){
                pre=y; continue;
            }
            swap(pre, y);
            for (k = 1; k <= n; k++) {
                for (j = 1; j <= n; j++) {
                    if (dp[k][j] > dp[k][y] + dp[y][j] + stop[y]) {
                        dp[k][j] = dp[k][y] + dp[y][j] + stop[y];
                    }
                }
            }
        }
        else {
            if (dp[y][z] >= big) anw.push(-1);
            else{
                if(pre==0) anw.push(dp[y][z]);
                else{
                    anw.push(min(dp[y][z], dp[y][pre]+dp[pre][z]+stop[pre]));
                }
            }
        }
    }
    while (!anw.empty()) {
        cout << anw.top() << "\n";
        anw.pop();
    }
}