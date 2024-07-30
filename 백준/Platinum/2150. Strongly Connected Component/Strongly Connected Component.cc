#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

vector<int> edge[10010];
vector<int> back[10010];
vector<int> result[10010];
stack<int> st;
bool visited[10010];
vector<pair<int, int>> pq;

void dfs(int x) {
    int i;
    visited[x] = true;
    for (i = 0; i < edge[x].size(); i++) {
        if (!visited[edge[x][i]]) {
            dfs(edge[x][i]);
        }
    }
    st.push(x);
}

void dfs_(int x, int sum) {
    int i;
    visited[x] = true;
    result[sum].push_back(x);
    for (i = 0; i < back[x].size(); i++) {
        if (!visited[back[x][i]]) {
            dfs_(back[x][i], sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n, m, i, j, x, y;
    cin >> n >> m;
    fill_n(&visited[0], 10010, false);
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        back[y].push_back(x);
    }
    for (i = 1; i <= n; i++) {
        sort(edge[i].begin(), edge[i].end());
        sort(back[i].begin(), back[i].end());
    }
    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    fill_n(&visited[0], 10010, false);
    int sum = 0;
    while (!st.empty()) {
        x = st.top();
        st.pop();
        if (visited[x]) continue;
        dfs_(x, sum++);
    }
    for (i = 0; i < sum; i++) {
        sort(result[i].begin(), result[i].end());
        pq.push_back({result[i][0], i});
    }
    sort(pq.begin(), pq.end());
    cout << sum << "\n";
    for (i = 0; i < sum; i++) {
        for (j = 0; j < result[pq[i].second].size(); j++) {
            cout << result[pq[i].second][j] << " ";
        }
        cout << "-1\n";
    }
}