#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool possible(const vector<ll>& a, ll d) {
    ll n = a.size();
    ll limit = 2 * n - 1;
    ll required = 0;

    for (ll x : a) {
        required += (x - 1) / d + 1;  // ceil(x / d)

        if (required > limit) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; ++tc) {
        int N;
        cin >> N;

        vector<ll> a(N);
        ll right = 0;

        for (ll& x : a) {
            cin >> x;
            right = max(right, x);
        }

        ll left = 0;  // 불가능
        // right = max(Ai)는 항상 가능

        while (left + 1 < right) {
            ll mid = left + (right - left) / 2;

            if (possible(a, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        cout << "#" << tc << ' ' << right << '\n';
    }
}