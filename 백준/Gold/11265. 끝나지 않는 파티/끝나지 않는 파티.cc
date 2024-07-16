#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int arr[510][510];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, k, x, y, z;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    while (m--) {
        cin >> x >> y >> z;
        if (arr[x][y] <= z) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}