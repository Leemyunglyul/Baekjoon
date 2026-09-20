#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

static int dist[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N, s;
        cin >> N >> s;
        --s;

        vector<ll> L(N), R(N);
        

        for (int i = 0; i < N; ++i) {
            cin >> L[i] >> R[i];
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> dist[i][j];
            }
        }

        // 모든 강의실 사이의 최소 이동 시간
        for (int k = 0; k < N; ++k) {
            const int* rowK = dist[k];

            for (int i = 0; i < N; ++i) {
                if (i == k) continue;

                int* rowI = dist[i];
                const int dik = rowI[k];

                for (int j = 0; j < N; ++j) {
                    rowI[j] = min(rowI[j], dik + rowK[j]);
                }
            }
        }

        // 수업 종료 시각 순으로 정렬
        vector<int> order(N);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            if (R[a] != R[b]) return R[a] < R[b];
            return a < b;
        });

        vector<ll> dp(N, -1);

        // 시작 강의실 s에서 i로 이동하여 첫 수업을 듣는 경우
        for (int i = 0; i < N; ++i) {
            ll start = max(L[i], static_cast<ll>(dist[s][i]));

            if (start <= R[i]) {
                dp[i] = R[i] - start;
            }
        }

        ll answer = 0;

        for (int a = 0; a < N; ++a) {
            int i = order[a];

            if (dp[i] == -1) continue;

            answer = max(answer, dp[i]);

            for (int b = a + 1; b < N; ++b) {
                int j = order[b];

                // i 수업이 끝난 뒤 j 강의실로 이동
                ll arrival = R[i] + dist[i][j];
                ll start = max(L[j], arrival);

                if (start > R[j]) continue;

                dp[j] = max(
                    dp[j],
                    dp[i] + R[j] - start
                );
            }
        }

        cout << '#' << tc << ' ' << answer << '\n';
    }

    return 0;
}
