#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, m, i, temp, s, e, anw;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    s = 1, e = 1;
    anw = 98765432111;
    while (s<n) {
        while (e < n && arr[e] - arr[s] < m) e++;
        if (arr[e] - arr[s] >= m) {
            anw = min(anw, arr[e] - arr[s]);
        }
        s++;
    }
    cout << anw;

    return 0;
}