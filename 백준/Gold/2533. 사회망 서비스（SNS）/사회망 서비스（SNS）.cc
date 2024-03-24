#include <iostream>
#include<vector>

using namespace std;

bool visited[1001000];
vector<int> node[1001000];
bool dp[1001000];

bool dfs(int now) {
    int i;
    bool ret=true;
    visited[now] = true;
    for (i = 0; i < node[now].size(); i++) {
        if (!visited[node[now][i]]) {
            ret &= dfs(node[now][i]);
        }
    }
    dp[now] = !ret;
    return !ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, x,y, i, mem, n;
    cin >> n;
    for (i = 1; i <= n-1; i++) {
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    if (n == 2) {
        cout << "1";
        return 0;
    }
    fill_n(&dp[0], n + 3, false);
    for (i = 1, mem=0; i <= n; i++) {
        if (node[i].size() > 1) {
            dp[i] = true;
            mem = i;
        }
    }
    dp[mem] = dfs(mem);
    for (i = 1, mem=0; i <= n; i++) {
        if (dp[i]) mem++;
    }
    cout << mem;
}
