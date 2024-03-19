#include <iostream>
#include<cmath>
#include <vector>
#include <tuple>
#include <map>
#include<algorithm>
#include<queue>

using namespace std;

int v, e;
vector<int> edge[10010];
vector<int> rev[10010];
vector<int> comp[10010];
vector<int> visit;
bool visited[10010];
vector<int> temp;

priority_queue<pair<int, int>> q;

void dfs(int now) {
    visited[now] = true;
    int i;
    sort(edge[now].begin(), edge[now].end());
    for (i = 0; i < edge[now].size(); i++) {
        if (visited[edge[now][i]]) continue;
        dfs(edge[now][i]);
    }
    visit.push_back(now);
}

void rev_dfs(int now, int order) {
    comp[order].push_back(now);
    visited[now] = true;
    int i;
    sort(rev[now].begin(), rev[now].end());
    for (i = 0; i < rev[now].size(); i++) {
        if (visited[rev[now][i]])continue;
        rev_dfs(rev[now][i], order);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    int i, j, x, y, order;
    fill_n(&visited[0], 10010, false);
    for (i = 1; i <= e; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        rev[y].push_back(x);
    }
    for (i = 1; i <=v; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    fill_n(&visited[0], 10010, false);
    for (i = v-1, order=0; i >=0; i--) {
        if (!visited[visit[i]]) {
            rev_dfs(visit[i], order++);
        }
    }
    cout << order << endl;
    for (i = 0; i < order; i++) {
        sort(comp[i].begin(), comp[i].end());
        q.push({ -comp[i][0], i });
    }
    while(!q.empty()) {
        i = q.top().second;
        q.pop();
        for (j = 0; j < comp[i].size(); j++) {
            cout << comp[i][j] << " ";
        }
        cout << "-1\n";
    }
}
