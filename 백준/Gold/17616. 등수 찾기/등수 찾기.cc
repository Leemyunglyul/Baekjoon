#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> edge[100100];
vector<int> pre[100100];
int cnt = -1; int rev_cnt = -1;
bool visited[100100];

void dfs(int x) {
    int i;
    if (visited[x]) return;
    visited[x] = true;
    cnt++;
    for (i = 0; i < edge[x].size(); i++) {
        dfs(edge[x][i]);
    }
}

void dfs2(int x) {
    int i;
    if (visited[x]) return;
    visited[x] = true;
    rev_cnt++;
    for (i = 0; i < pre[x].size(); i++) {
        dfs2(pre[x][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, x, i, j,k, y ;
    cin >> n >> m >> k;
    fill_n(&visited[0], 100100, false);
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        pre[y].push_back(x);
    }
    dfs(k);
    fill_n(&visited[0], 100100, false); 
    dfs2(k);
    cout << rev_cnt + 1 << " " << n - cnt << endl;
    return 0;
}