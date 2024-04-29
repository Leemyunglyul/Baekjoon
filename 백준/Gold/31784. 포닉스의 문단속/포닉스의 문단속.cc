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

string x;

int tx(int n) {
    int idx = x[n] - 65;
    if (idx == 0) return 0;
    else return (26 - idx);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, i;
    cin >> n >> k;
    cin >> x;
    for (i = 0; i <= n - 2; i++) {
        int idx = tx(i);
        if (idx <= k) {
            x[i] = 'A';
            k -= idx;
        }
       // cout << k << endl;
    }
    k = k % 26;
    //cout << k << endl;
    int idx = tx(n-1);
    if (idx > k) {
        x[n - 1] += k;
    }
    else {
        x[n - 1] = 'A'+k-idx;
    }
    cout << x;
    

    return 0;
}