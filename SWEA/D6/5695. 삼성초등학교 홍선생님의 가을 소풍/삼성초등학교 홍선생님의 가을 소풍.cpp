#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;

        vector<int> bff(N + 1);
        vector<int> indegree(N + 1, 0);
        vector<int> depth(N + 1, 1);
        vector<bool> visited(N + 1, false);

        for (int i = 1; i <= N; ++i) {
            cin >> bff[i];
            ++indegree[bff[i]];
        }

        queue<int> q;

        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int next = bff[cur];

            depth[next] = max(depth[next], depth[cur] + 1);

            if (--indegree[next] == 0) {
                q.push(next);
            }
        }

        int longestCycle = 0;
        int pairTotal = 0;

        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0 || visited[i]) {
                continue;
            }

            int cur = i;
            int length = 0;

            do {
                visited[cur] = true;
                ++length;
                cur = bff[cur];
            } while (cur != i);

            if (length == 2) {
                pairTotal += depth[i] + depth[bff[i]];
            } else {
                longestCycle = max(longestCycle, length);
            }
        }

        cout << '#' << tc << ' '
             << max(longestCycle, pairTotal) << '\n';
    }

    return 0;
}