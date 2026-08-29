#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

vector<int> dijkstra(int start, const vector<vector<pii>>& graph) {
    int n = graph.size() - 1;

    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // 이미 더 짧은 거리로 방문했다면 무시
        if (curDist > dist[cur])
            continue;

        for (auto next : graph[cur]) {
            int nextNode = next.first;
            int cost = next.second;

            int nextDist = curDist + cost;

            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M, X;
        cin >> N >> M >> X;

        vector<vector<pii>> graph(N + 1);
        vector<vector<pii>> reverseGraph(N + 1);

        for (int i = 0; i < M; i++) {
            int x, y, c;
            cin >> x >> y >> c;

            // 원래 방향
            graph[x].push_back({y, c});

            // 반대 방향
            reverseGraph[y].push_back({x, c});
        }

        // X -> 각 집
        vector<int> fromX = dijkstra(X, graph);

        // 각 집 -> X
        // 간선을 뒤집으면 X -> 각 집 문제로 바뀜
        vector<int> toX = dijkstra(X, reverseGraph);

        int answer = 0;

        for (int i = 1; i <= N; i++) {
            answer = max(answer, fromX[i] + toX[i]);
        }

        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}