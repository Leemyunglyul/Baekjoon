#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>

using namespace std;

long long dp[300100];
long long score[300100];
long long ht[300100];
long long dd[300100];
long long n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long i, idx;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> ht[i];
    }
    for (i = 2; i <= n; i++) cin >> score[i];
    for (i = 2; i <= n; i++) cin >> dd[i];
    for (i = 2; i <= n; i++) {
        if (dd[i] + ht[i] > ht[1]) {
            dp[i] = dp[i - 1];
            continue;
        }
        idx = upper_bound(ht + 1, ht + i, dd[i] + ht[i], greater<int>()) - ht - 1;
        dp[i] = max(dp[idx] + score[i], dp[i - 1]);
    }
    cout << dp[n];

    return 0;
}