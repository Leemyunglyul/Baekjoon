#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

bool edge[510][510];
int pre[510];//그 이전에 몇개 있는지
int last[510];//작년 등수대로 1등~

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, n, i, j, x, m, y;
    cin >> testn;
    while (testn--) {
        cin >> n;
        fill_n(&edge[0][0], 510 * 510, false);
        for (i = 1; i <= n; i++) {
            cin >> x;
            last[i] = x;
            pre[x] = i-1;
        }
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                edge[last[i]][last[j]] = true;
            }
        }
        cin >> m;
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            if (edge[x][y]) {
                edge[x][y] = false;
                edge[y][x] = true;
                pre[x]++; pre[y]--;
            }
            else {
                edge[x][y] = true;
                edge[y][x] = false;
                pre[x]--; pre[y]++;
            }
        }
        queue<int> q; vector<int> v;
        for (i = 1; i <= n; i++) {
            if (pre[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            v.push_back(p);
            for (i = 1; i <= n; i++) {
                if (edge[p][i]) {
                    pre[i]--;
                    if (pre[i] == 0) q.push(i);
                }
            }
        }
        if (v.size() != n) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }cout << "\n";
        }

    }
    return 0;

}