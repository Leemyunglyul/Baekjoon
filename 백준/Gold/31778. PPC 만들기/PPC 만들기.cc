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

long long arr[200100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, i, j, s, e;
    string x;
    cin >> n >> m;
    cin >> x;
    s = 0; e = n - 1;
    while (s < e) {
        if (m <= 0) break;
        while (s<=n-1 && x[s] != 'C') s++;
        while (e >= 0 && x[e] != 'P') e--;
        if (s >= e) break;

        if (x[s] == 'C' && x[e]=='P') {
            x[e] = 'C';
            x[s] = 'P';
            s++;
            e--;
            m--;
        }
    }   
    long long anw = 0;
    for (i = 1; i <= n - 1; i++) {
        arr[i] = arr[i - 1];
        if (x[i - 1] == 'P') arr[i]++;
    }
    for (i = 0; i <= n - 1; i++) {
        if (x[i] == 'C') {
            anw += ((arr[i] - 1) * arr[i]) / 2;
        }
    }
    cout << anw;


    return 0;
}