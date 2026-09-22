#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;

struct Edge {
    int to;
    int limit;
    int length;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N, M, D;
        cin >> N >> M >> D;

        vector<vector<Edge>> graph(N);

        for (int i = 0; i < M; ++i) {
            int S, E, V, L;
            cin >> S >> E >> V >> L;
            graph[S].push_back({E, V, L});
        }

        const double INF = 1e100;

        vector<vector<double>> dist(
            N, vector<double>(501, INF)
        );

        // parent[도시][속도] = {이전 도시, 이전 속도}
        vector<vector<pair<int, int>>> parent(
            N, vector<pair<int, int>>(501, {-1, -1})
        );

        // {누적 시간, 도시, 현재 속도}
        using State = tuple<double, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][70] = 0.0;
        pq.push({0.0, 0, 70});

        int endSpeed = -1;

        while (!pq.empty()) {
            auto [time, city, speed] = pq.top();
            pq.pop();

            if (time > dist[city][speed]) continue;

            // 목적지 상태가 처음 꺼내지면 전체 최단 시간 확정
            if (city == D) {
                endSpeed = speed;
                break;
            }

            for (const Edge& e : graph[city]) {
                int nextSpeed = (e.limit == 0 ? speed : e.limit);
                double nextTime =
                    time + static_cast<double>(e.length) / nextSpeed;

                if (nextTime < dist[e.to][nextSpeed]) {
                    dist[e.to][nextSpeed] = nextTime;
                    parent[e.to][nextSpeed] = {city, speed};
                    pq.push({nextTime, e.to, nextSpeed});
                }
            }
        }

        vector<int> path;

        // 도달 불가능한 경우의 출력 규칙은 문제에 명시되어 있지 않음
        if (endSpeed != -1) {
            int city = D;
            int speed = endSpeed;

            while (city != -1) {
                path.push_back(city);

                auto [prevCity, prevSpeed] = parent[city][speed];
                city = prevCity;
                speed = prevSpeed;
            }

            reverse(path.begin(), path.end());
        }

        cout << '#' << tc;
        for (int city : path) {
            cout << ' ' << city;
        }
        cout << '\n';
    }

    return 0;
}