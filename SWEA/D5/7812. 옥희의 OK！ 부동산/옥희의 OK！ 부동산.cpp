#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        long long M;
        cin >> N >> M;

        vector<long long> prefix(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            int price;
            cin >> price;
            prefix[i] = prefix[i - 1] + price;
        }

        int answer = 0;

        for (int left = 1; left <= N; ++left) {
            long long target = prefix[left - 1] + M;

            auto it = lower_bound(
                prefix.begin() + left,
                prefix.end(),
                target
            );

            if (it != prefix.end() && *it == target) {
                ++answer;
            }
        }

        cout << '#' << tc << ' ' << answer << '\n';
    }
}