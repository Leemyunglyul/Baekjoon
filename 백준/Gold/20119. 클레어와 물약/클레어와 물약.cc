#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>

using namespace std;

vector<pair<int, int>> edge[200100];
int pre[200100][2];
bool visited[200100];
int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int i, j, k, s, e, x;
    for (i = 1; i <= m; i++) {
        cin >> k;
        vector<int> v;
        for (j = 1; j <= k; j++) {
            cin >> s;
            v.push_back(s);
        }
        cin >> e;
        pre[i][0] = e;//결과
        pre[i][1] = k;//갯수
        for (j = 0; j < k; j++) {
            edge[v[j]].push_back({i, e});
        }
    }
    cin >> k;
    queue<int> q;
    fill_n(&visited[0], 200100, false);
    int anw = 0;
    for (i = 1; i <= k; i++) {
        cin >> x;
        q.push(x);
        visited[x] = true;
    }
    while (!q.empty()) {
        int vt = q.front();
        q.pop();
        anw++;

        for (i = 0; i < edge[vt].size(); i++) {
            int now = edge[vt][i].second;
            int idx = edge[vt][i].first;
            pre[idx][1]--;
            if (pre[idx][1] <= 0 && !visited[pre[idx][0]]) {
                q.push(pre[idx][0]);
                visited[pre[idx][0]] = true;
            }
        }
    }
    
    cout << anw << "\n";
    for (i = 1; i <= n; i++) {
        if (visited[i]) cout << i << " ";
    }

    return 0;
}