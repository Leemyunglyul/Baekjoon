#include <string>
#include <vector>
#include <queue>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<vector<int>> graph(n);

    for (const auto& edge : path) {
        int a = edge[0];
        int b = edge[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> before(n, -1);

    for (const auto& condition : order) {
        int first = condition[0];
        int second = condition[1];

        before[second] = first;
    }

    if (before[0] != -1) {
        return false;
    }

    vector<bool> visited(n, false);

    vector<int> waiting(n, -1);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    int visitCount = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (waiting[current] != -1) {
            int room = waiting[current];

            if (!visited[room]) {
                visited[room] = true;
                visitCount++;
                q.push(room);
            }
        }

        for (int next : graph[current]) {
            if (visited[next]) {
                continue;
            }

            if (before[next] != -1 && !visited[before[next]]) {
                waiting[before[next]] = next;
                continue;
            }

            visited[next] = true;
            visitCount++;
            q.push(next);
        }
    }

    return visitCount == n;
}