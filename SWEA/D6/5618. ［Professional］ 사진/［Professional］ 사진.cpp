#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;

        // idx[id] = 압축된 사람 번호
        unordered_map<long long, int> idx;
        idx.reserve(N * 2);

        vector<long long> id(N);

        // pos[p][i] = p번째 사진에서 i번 사람의 위치
        vector<vector<int>> pos(5, vector<int>(N));

        // 첫 번째 사진을 이용해 ID를 0 ~ N-1로 압축
        for (int i = 0; i < N; ++i) {
            long long x;
            cin >> x;

            id[i] = x;
            idx[x] = i;
            pos[0][i] = i;
        }

        // 나머지 4장의 사진
        for (int p = 1; p < 5; ++p) {
            for (int j = 0; j < N; ++j) {
                long long x;
                cin >> x;

                int person = idx[x];
                pos[p][person] = j;
            }
        }

        vector<int> order(N);
        iota(order.begin(), order.end(), 0);

        // 두 사람의 5개 사진에서의 상대 순서를 비교
        auto cmp = [&](int a, int b) {
            int cnt = 0;

            for (int p = 0; p < 5; ++p) {
                if (pos[p][a] < pos[p][b]) {
                    ++cnt;
                }
            }

            // 5장 중 최소 3장에서 a가 앞이라면
            // 실제 원래 줄에서도 a가 앞이다.
            return cnt >= 3;
        };

        sort(order.begin(), order.end(), cmp);

        cout << "#" << tc << " ";

        for (int i = 0; i < N; ++i) {
            if (i) cout << ' ';
            cout << id[order[i]];
        }

        cout << '\n';
    }

    return 0;
}