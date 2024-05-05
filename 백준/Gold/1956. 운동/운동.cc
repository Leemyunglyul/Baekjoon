#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long arr[410][410];
long long v, e;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    long long i, x, y, d, j, k;
    long long big = 987654321;
    fill_n(&arr[0][0], 410 * 410, big);
    for (i = 1; i <= e; i++) {
        cin >> x >> y >> d;
        arr[x][y] = d;
    }
    for (k = 1; k <= v; k++) {
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for (j = 1; j <= v; j++) {
        big = min(arr[j][j], big);
    }
    if (big>=987654321) cout << "-1";
    else cout << big;
}