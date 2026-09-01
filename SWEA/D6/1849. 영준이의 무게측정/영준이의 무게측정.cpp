#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parent[100010];
long long weight[100010];

int pathBuf[100010];

int find(int x) {
    int cnt = 0;
    int cur = x;

    while (cur != parent[cur]) {
        pathBuf[cnt++] = cur;
        cur = parent[cur];
    }

    int root = cur;

    long long acc = 0;

    // 뒤에서부터 누적해서
    // weight[node] = node의 무게 - root의 무게
    for (int i = cnt - 1; i >= 0; i--) {
        int node = pathBuf[i];

        acc += weight[node];

        weight[node] = acc;
        parent[node] = root;
    }

    return root;
}


void unionn(int x, int y, long long z) {

    // 중요: 원래 x, y를 보존해야 함
    int px = find(x);
    int py = find(y);

    if (px != py) {

        parent[py] = px;
        weight[py] = weight[x] + z - weight[y];
    }
}


void solve() {

    int n, m;
    cin >> n >> m;

    char c;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        weight[i] = 0;
    }

    for (int i = 0; i < m; i++) {

        cin >> c;

        if (c == '!') {

            int x, y;
            long long z;

            cin >> x >> y >> z;

            // 문제 그대로
            // y - x = z
            unionn(x, y, z);

        } else {

            int x, y;
            cin >> x >> y;

            int a = find(x);
            int b = find(y);

            if (a != b) {
                cout << "UNKNOWN ";
            }
            else {
                // y가 x보다 얼마나 무거운가
                cout << weight[y] - weight[x] << " ";
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        cout << "#" << tc << " ";

        solve();

        cout << '\n';
    }

    return 0;
}