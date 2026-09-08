#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int size) : size(size), tree(size + 1, 0) {}

    void update(int idx) {
        while (idx <= size) {
            tree[idx]++;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int result = 0;

        while (idx > 0) {
            result += tree[idx];
            idx -= idx & -idx;
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        ll P;

        cin >> N >> P;

        vector<ll> prefix(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            ll score;
            cin >> score;

            prefix[i] = prefix[i - 1] + score - P;
        }

        vector<ll> compressed = prefix;

        sort(compressed.begin(), compressed.end());
        compressed.erase(
            unique(compressed.begin(), compressed.end()),
            compressed.end()
        );

        FenwickTree fenwick(compressed.size());

        ll answer = 0;

        for (ll value : prefix) {
            int idx = lower_bound(
                compressed.begin(),
                compressed.end(),
                value
            ) - compressed.begin() + 1;

            answer += fenwick.query(idx);

            fenwick.update(idx);
        }

        cout << '#' << tc << ' ' << answer << '\n';
    }

    return 0;
}