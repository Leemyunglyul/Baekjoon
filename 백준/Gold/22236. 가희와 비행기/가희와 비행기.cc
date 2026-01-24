#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;

long long dp[4010];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int d;
    long long m;
    cin >> d >> m;

    int n = d / 2;
    int target = n - 1;

    dp[0] = 1;
    if (target >= 1) dp[1] = 1;

    for (int i = 2; i <= target; i++) {
        for (int j = 0; j < i; j++) {
            long long term = (dp[j] * dp[i - 1 - j]) % m;
            dp[i] = (dp[i] + term) % m;
        }
    }

    cout << dp[target] % m << endl;

    return 0;
    
    return 0;
}