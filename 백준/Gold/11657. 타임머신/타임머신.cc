#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>


using namespace std;

long long int dp[510];
vector<tuple<int, int, int>> list;
int n, m;

bool neg_cycle() {
    int i, j, arr[510], s, d, w;
    for (i = 1; i <= n; i++) {
        arr[i] = dp[i];
    }
    for (i = 1, dp[1] = 0; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            s = get<0>(list[j]);
            d = get<1>(list[j]);
            w = get<2>(list[j]);
            if (dp[s] == INT_MAX) continue;
            dp[d] = min(dp[d], dp[s] + w);
        }
    }
    for (i = 1; i <= n; i++) {
        if(arr[i] != dp[i]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int s, d, w, i, j;
    cin >> n >> m;
    fill_n(&dp[0], 510, INT_MAX);
    for (i = 0; i < m; i++) {
        cin >> s >> d >> w;
        list.push_back({ s, d, w });
    }
    if (n == 1) return 0;
    for (i = 1, dp[1]=0; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            s = get<0>(list[j]);
            d = get<1>(list[j]);
            w = get<2>(list[j]);
            if (dp[s] == INT_MAX) continue;
            dp[d] = min(dp[d], dp[s] + w);
        }
    }
    if (neg_cycle()) {
        cout << "-1";
        return 0;
    }
    for (i = 2; i <= n; i++) {
        if (dp[i] == INT_MAX) cout << "-1\n";
        else cout << dp[i] << "\n";
    }
}