#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;

int bite[110];
int sos[110];
int cost[110][10010];
bool pos[110][10010];
int big = 2100000000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, i, sum, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> bite[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> sos[i];
    }
    fill_n(&pos[0][0], 110*10010, false);
    pos[0][0] = true;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 10000; j++) {
            if (pos[i-1][j]) {
                pos[i][j + sos[i]] = true;
                pos[i][j] = true;
                cost[i][j] = max(cost[i-1][j], cost[i][j]);
                cost[i][j + sos[i]] = max(cost[i-1][j]+bite[i], cost[i][j+sos[i]]);
            }
        }
    }
    int anw = big;
    for (i = 0; i <= 10000; i++) {
        if (pos[i] && cost[n][i] >= m) {
            anw = min(anw, i);
        }
    }
    cout << anw;
}