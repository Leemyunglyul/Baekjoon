#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int arr[102][102][102];
queue<tuple<int, int, int>> q;
int m1[6] = {1, -1, 0, 0, 0, 0};
int m2[6] = { 0, 0, 1, -1, 0, 0 };
int m3[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, h, i, j, k, ss;
    cin >> n >> m >> h;
    for (i = 1, ss=0; i <= h; i++) {
        for (j = 1; j <= m; j++) {
            for (k = 1; k <= n; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    q.push({ i, j, k });
                }
                if (arr[i][j][k] >= 0) ss++;
            }
        }
    }
    int anw = 0;
    int sum = 0;
    while (!q.empty()) {
        int r1 = get<0>(q.front());
        int r2 = get<1>(q.front());
        int r3 = get<2>(q.front());
        anw = arr[r1][r2][r3];
        sum++;
        q.pop();

        for (i = 0; i <= 5; i++) {
            int c1 = r1 + m1[i];
            int c2 = r2 + m2[i];
            int c3 = r3 + m3[i];
            if (c1<1 || c1>h || c2<1 || c2>m || c3<1 || c3>n) continue;

            if (arr[c1][c2][c3] == 0) {
                arr[c1][c2][c3] = anw + 1;
                q.push({ c1, c2, c3 });
            }
        }
    }
    if (sum == ss)cout << anw-1;
    else cout << "-1";

}