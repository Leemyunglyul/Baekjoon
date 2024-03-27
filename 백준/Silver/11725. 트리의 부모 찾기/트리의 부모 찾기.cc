#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[100010];
bool visited[100010];
int parent[100010];

void bfs() {
    fill_n(&visited[0], 100010, false);

    queue<int> q;
    q.push(1);
    visited[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < edge[x].size(); i++) {
            if (!visited[edge[x][i]]) {
                visited[edge[x][i]] = true;
                parent[edge[x][i]] = x;
                q.push(edge[x][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, sum, x, y;
    cin >> n;
    for (i = 1, sum = 0; i <= n-1; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs();
    for (i = 2; i <= n; i++) cout << parent[i] << "\n";
}