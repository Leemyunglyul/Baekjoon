#include <iostream>
#include<vector>

using namespace std;

bool visited[100100];
vector<int> node[100100];
int dp[100100];
int n = 0;
int root;

int dfs(int now) {
    if (dp[now] != 0) return dp[now];
    int i, ret;
    visited[now] = true;
    for (i = 0, ret=1; i < node[now].size(); i++) {
        if (!visited[node[now][i]]) {
            ret+=dfs(node[now][i]);
        }
    }
    dp[now] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, x,y, i;
    cin >> n >> root >> q;
    for (i = 1; i <= n-1; i++) {
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dp[root] = dfs(root);
    for (i = 0; i < q; i++) {
        cin >> x;
        cout << dp[x] << "\n";
    }
}
