#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

long long big = 987654321987654321;
long long dp[210][210];
long long path[210][210];
long long stop[210];
vector<tuple<int, int, int>> query;
stack<long long> anw;
long long n, m, q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    long long i, j, x, y, w, k, z, l;

    fill_n(&path[0][0], 210*210, big);
    for (i = 1; i <= n; i++) {
        cin >> stop[i];
        //path[i][i] = 0;
    }
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        path[x][y] = min(path[x][y], w);
        path[y][x] = min(path[y][x], w);
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = path[i][j];
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + stop[k]);
            }
        }
    }
    long long pre = -1;
    long long temp;
    for (l = 1; l <= q; l++) {
        cin >> x >> y >> z;
        if (x == 1) {
            stop[y] += z;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    dp[i][j] = path[i][j];
                }
            }
            for (k = 1; k <= n; k++) {
                if (k == y) continue;
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + stop[k]);
                    }
                }
            }
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][y] + dp[y][j] + stop[y]);
                }
            }
        }
        else {
            if (dp[y][z] == big) cout << "-1\n";
            else cout<<dp[y][z]<<"\n";
        }
    }
    
   /*int pre = -1;
    for (i = q - 1; i >= 0; i--) {
        x = get<0>(query[i]);
        y = get<1>(query[i]);
        z = get<2>(query[i]);
        if (x == 1) {
            if (pre == -1);
            else {
                for (k = 1; k <= n; k++) {
                    if (k == pre) continue;
                    for (j = 1; j <= n; j++) {
                        if (j == pre) continue;
                        dp[k][j] = min(dp[k][j], dp[k][pre] + dp[pre][j] + stop[pre]);
                    }
                }
            }
            stop[y] -= z;
            pre = y;
        }
        else {
            if (pre == -1);
            else {
                dp[y][z] = min(dp[y][z], dp[y][pre] + dp[pre][z] + stop[pre]);
            }
            if (dp[y][z] == big) anw.push(-1);
            else anw.push(dp[y][z]);
        }
    }
    while (!anw.empty()) {
        cout << anw.top() << "\n";
        anw.pop();
    }*/
}