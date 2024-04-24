#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>

using namespace std;

int arr[1010], dp[1010];
int pre[1010];
vector<int> edge[1010];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, n, x, y, i, j, m, fin;
    cin >> testn;
    while (testn--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            cin >> arr[i];
            edge[i].clear();
            pre[i] = 0;
        }
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            edge[x].push_back(y);
            pre[y]++;
        }
        cin >> fin;
        for (i = 1; i <= n; i++) {
            if (pre[i] == 0) {
                q.push(i);
            }
            dp[i] = 0;
        }
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            dp[idx] += arr[idx];

            for (i = 0; i < edge[idx].size(); i++) {
                int t = edge[idx][i];
                pre[t]--;
                dp[t] = max(dp[t], dp[idx]);
                if (pre[t] == 0) q.push(t);
            }
        }
        cout<< dp[fin] << "\n";
    }

    return 0;
}