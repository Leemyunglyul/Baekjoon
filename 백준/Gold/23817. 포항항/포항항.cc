#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[1010][1010];
int dist_map[1010][1010];
int adj[22][22];
bool visited_node[22];
int ans = 2e9;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Point {
    int x, y;
};

vector<Point> nodes;

void bfs_dist(int start_idx) {
    memset(dist_map, -1, sizeof(dist_map));
    queue<Point> q;
    
    q.push({nodes[start_idx].x, nodes[start_idx].y});
    dist_map[nodes[start_idx].x][nodes[start_idx].y] = 0;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (arr[nx][ny] == 0) continue;
            if (dist_map[nx][ny] != -1) continue;

            dist_map[nx][ny] = dist_map[p.x][p.y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < nodes.size(); i++) {
        adj[start_idx][i] = dist_map[nodes[i].x][nodes[i].y];
    }
}

void dfs(int curr, int cnt, int sum) {
    if (sum >= ans) return;

    if (cnt == 5) {
        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i < nodes.size(); i++) {
        if (!visited_node[i] && adj[curr][i] != -1) {
            visited_node[i] = true;
            dfs(i, cnt + 1, sum + adj[curr][i]);
            visited_node[i] = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    char c;
    Point start;
    vector<Point> k_list;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '.') arr[i][j] = 1;
            else if (c == 'X') arr[i][j] = 0;
            else if (c == 'S') {
                arr[i][j] = 1;
                start = {i, j};
            } else if (c == 'K') {
                arr[i][j] = 1;
                k_list.push_back({i, j});
            }
        }
    }

    if (k_list.size() < 5) {
        cout << -1 << "\n";
        return;
    }

    nodes.push_back(start);
    for (auto p : k_list) nodes.push_back(p);

    for (int i = 0; i < nodes.size(); i++) {
        bfs_dist(i);
    }

    dfs(0, 0, 0);

    if (ans == 2e9) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}