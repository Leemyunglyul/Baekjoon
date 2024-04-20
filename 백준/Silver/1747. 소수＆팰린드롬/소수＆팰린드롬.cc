#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

bool arr[2100000];
vector<int> v;

bool check(int x) {
    string y = to_string(x);
    int s = 0; int e = y.size() - 1;
    if (s == e) return true;
    while (s <= e) {
        if (y[s] != y[e]) return false;
        s++; e--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j;
    fill_n(&arr[0], 2010000, true);
    for (i = 2; i <= 1010000; i++) {
        if (!arr[i]) continue;
        for (j = 2 * i; j <= 1010000; j+=i) {
            arr[j] = false;
        }
        if (check(i)) {
            v.push_back(i);
        }
    }

    cin >> n;
    cout << v[lower_bound(v.begin(), v.end(), n) - v.begin()];

    return 0;
}