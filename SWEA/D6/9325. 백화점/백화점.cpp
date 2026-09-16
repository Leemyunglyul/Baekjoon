#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; ++tc) {
        int N, D;
        ll P;
        cin >> N >> P >> D;

        vector<ll> sum(N + 1);
        for (int i = 1; i <= N; ++i) {
            ll x;
            cin >> x;
            sum[i] = sum[i - 1] + x;
        }

        vector<int> dq(N + 1);
        int head = 0, tail = 0;
        int left = 1, answer = D;

        auto discount = [&](int end) {
            return sum[end] - sum[end - D];
        };

        for (int right = D; right <= N; ++right) {
            while (head < tail &&
                   discount(dq[tail - 1]) <= discount(right))
                --tail;

            dq[tail++] = right;

            while (sum[right] - sum[left - 1] -
                       discount(dq[head]) > P) {
                ++left;

                while (head < tail && dq[head] < left + D - 1)
                    ++head;
            }

            answer = max(answer, right - left + 1);
        }

        cout << '#' << tc << ' ' << answer << '\n';
    }
}