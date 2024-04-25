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

vector<pair<int, int>> edge[10100];
bool visited[10100];
int n;

pair<int, int> dfs(int now, int num) {
    int i, a, b;
    pair<int, int> temp;
    visited[now] = true;
    // cout<<now<<" " << num << endl;
    for (i = 0, b = 0; i < edge[now].size(); i++) {
        int idx = edge[now][i].first;
        int d = edge[now][i].second;
        if (!visited[idx]) {
            temp = dfs(idx, num + d);
            if (temp.second > b) {
                b = temp.second;
                a = temp.first;
            }
        }
    }
    if (b == 0) return { now, num };
    else return { a, b };
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int i, j, x, y, d, k;
    for (i = 1; i <= n-1; i++) {
        cin >> x >> y >> d;
        edge[x].push_back({ y, d });
        edge[y].push_back({ x, d });
    }
    fill_n(&visited[0], 10100, false);
    for (k = 1; k <= n; k++) {
        if (edge[k].size() == 1) break;
    }
    visited[k] = true;
    int far = dfs(k, 0).first;
    fill_n(&visited[0], 10100, false);
    visited[far] = true;
    cout << dfs(far, 0).second;


    return 0;
}