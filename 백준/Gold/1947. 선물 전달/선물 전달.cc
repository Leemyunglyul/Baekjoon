#include <iostream>
#define mod 1000000000

using namespace std;
long long int dp[1000010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, i;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    for (i = 3; i <= n; i++) {
        dp[i] = (i - 1) * ((dp[i - 1] + dp[i - 2]) % mod)%mod;
    }
    cout << dp[n];
}
