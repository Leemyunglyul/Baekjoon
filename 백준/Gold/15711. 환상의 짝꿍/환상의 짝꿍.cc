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

bool arr[3001000];
vector<int> v;

bool prime(long long x) {
    long long i;
    for (i = 0; i < v.size(); i++) {
        if (v[i] >= x) break;
        if (x%v[i]==0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long testn, x, y, sum, i, j;
    fill_n(&arr[0], 3001000, true);
    for (i = 2; i <= 3000000; i++) {
        if (!arr[i]) continue;
        v.push_back(i);
        for (j = 2 * i; j <= 3000000; j += i) {
            arr[j] = false;
        }
    }
    cin >> testn;
    while (testn--) {
        cin >> x >> y;
        if (x + y == 2 || x+y==3) {
            cout << "NO\n";
            continue;
        }
        sum = x + y;
        if (sum % 2 == 0) {
            cout << "YES\n";
        }
        else {
            sum -= 2;
            if (prime(sum)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}