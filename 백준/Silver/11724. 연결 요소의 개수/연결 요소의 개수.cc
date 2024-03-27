#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> edge[1010];
bool visited[1010];

void dfs(int now) {
    for (int i = 0; i < edge[now].size(); i++) {
        if (!visited[edge[now][i]]) {
            visited[edge[now][i]] = true;
            dfs(edge[now][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, sum, x, y;
    cin >> n >> m;
    for (i = 0, sum = 0; i < m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (i = 1; i <=n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        sum++;
        dfs(i);
    }
    cout << sum;
}