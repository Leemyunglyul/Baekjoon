#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int pos[20010];
//bool visited[20010];
vector<int> edge[20010];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, n, v, i, j, x, y;
    cin >> testn;
    while (testn--) {
        cin >> n >> v;
        for (i = 1; i <= n; i++) edge[i].clear();
        fill_n(&pos[0], 20010, 0);
        for (i = 1; i <= v; i++) {
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        bool anw = true;
        //fill_n(&visited[0], 20010, false);
        for (i = 1; i <= n; i++) {
            if (pos[i]==0) {
                q.push({ i, 1 });
                pos[i] = 1;
                
                while (!q.empty()) {
                    int idx = q.front().first;
                    int team = q.front().second;
                    q.pop();

                    for (i = 0; i < edge[idx].size(); i++) {
                        int nextt = edge[idx][i];
                        if (pos[nextt] > 0) {
                            if (pos[nextt] == team) {
                                anw = false;
                            }
                        }
                        else {
                            pos[nextt] = 3 - team;
                            q.push({ nextt, pos[nextt] });
                        }
                    }
                }
            }
        }
        if (anw) cout << "YES\n";
        else cout << "NO\n";
    }
}