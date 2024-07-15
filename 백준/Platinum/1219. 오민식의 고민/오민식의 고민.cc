#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

long long city[52];
vector<tuple<int, int, int>> edge;
long long dp[52];
long long big = 98765432187654321;
long long n, s, e, m, i, j, k, x, y, cost;
bool rev[52][52];
bool reach[52];

bool neg_cycle() {
    long long arr[52];
    for (i = 0; i < n; i++) {
        arr[i] = dp[i];
    }
    for (j = 0; j < edge.size(); j++) {
        x = get<0>(edge[j]);
        y = get<1>(edge[j]);
        cost = get<2>(edge[j]);
        if (arr[x] == big) continue;
        arr[y] = min(arr[y], arr[x] + cost+city[y]);
    }
    for (i = 0; i < n; i++) {
        if ((arr[i] != dp[i]) && reach[i]) {
            //cout << i << endl;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill_n(&rev[0][0], 52 * 52, false);
    fill_n(&reach[0], 52, false);
    cin >> n >> s >> e >> m;
    for (i = 0, reach[e]=true; i < m; i++) {
        cin >> x >> y >> cost;
        edge.push_back({ x, y, cost });
        rev[y][x] = true;
    }
    for (i = 0; i < n; i++) {
        cin >> x;
        city[i] = -x;
    }
    fill_n(&dp[0], 52, big);
    dp[s] = city[s];
    for (i = 1; i < n; i++) {
        for (j = 0; j < edge.size(); j++) {
            x = get<0>(edge[j]);
            y = get<1>(edge[j]);
            cost = get<2>(edge[j]);
            if (dp[x] == big) continue;
            dp[y] = min(dp[y], dp[x] + city[y] + cost);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (reach[j] && rev[j][k]) reach[k] = true;
            }
        }
    }
    if (dp[e] == big) cout << "gg";
    else if (neg_cycle()) cout << "Gee";
    else cout << -dp[e];
}