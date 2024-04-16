#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int arr[60][60];
int d[60];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x, y, i, j, k, z;
    cin >> n;
    fill_n(&arr[0][0], 60 * 60, n);
    cin >> x >> y;
    arr[x][y] = 1;
    arr[y][x] = 1;
    while(x!=-1 || y!=-1) {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for (k = 1; k <= n; k++) {
        for (j = 1; j <= n; j++) {
            for (i = 1; i <= n; i++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for (i = 1, z=100; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) continue;
            d[i]=max(d[i], arr[i][j]);
        }
        z = min(d[i], z);
    }
    vector<int> v;
    for (i = 1; i <= n; i++) {
        if (z == d[i]) v.push_back(i);
    }
    cout << z << " " << v.size() << "\n";
    for (i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}