#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

long long arr[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, x, i;
    long long big = 987654321987654;
    cin >> n >> x;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (i = 1; i <= n-1; i++) {
        big = min(big, arr[i] + arr[i + 1]);
    }
    cout << big * x;

    return 0;
}