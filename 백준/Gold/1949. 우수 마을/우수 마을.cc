#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector<int> edge[10010];
int arr[10010];
int dp[10010][2] = { 0 };
bool visited[10010];
//0: 포함X, 1: 포함

void dfs(int now) {
    int i;
    for (i = 0; i < edge[now].size(); i++) {
        if (!visited[edge[now][i]]) {
            visited[edge[now][i]] = true;
            dfs(edge[now][i]);
            dp[now][1] += dp[edge[now][i]][0];
            dp[now][0] += max(dp[edge[now][i]][1], dp[edge[now][i]][0]);
        }
    }
    dp[now][1] += arr[now];
    //cout << now << ":" << dp[now][0] << " " << dp[now][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, x, y;
    cin >> n;
    fill_n(&visited[0], 10010, false);
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    visited[1] = true;
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}