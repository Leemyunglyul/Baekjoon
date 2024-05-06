#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int arr[1010][1010];
queue<tuple<int, int, int, int>> q;
bool visited[1010][1010][2];
int m1[4] = {1, -1, 0, 0};
int m2[4] = { 0, 0, 1, -1 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, r, c, d, foo;
    cin >> n >> m;
    char x;
    fill_n(&visited[0][0][0], 1010 * 1010 * 2, false);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> x;
            arr[i][j] = x - 48;
        }
    }
    q.push({ 1, 1, 1, 1 });
    visited[1][1][0] = true;
    visited[1][1][1] = true;
    r = 0; c = 0; d = 0;
    while (!q.empty()) {
        r = get<0>(q.front());
        c = get<1>(q.front());
        d = get<2>(q.front());
        foo = get<3>(q.front());
        //cout << r << " " << c <<"=="<<d << endl;
        if (r == n && c == m) {
            break;
        }
        q.pop();

        for (i = 0; i <= 3; i++) {
            int r2 = r + m1[i];
            int c2 = c + m2[i];

            if (r2<1 || r2>n || c2 < 1 || c2 > m) continue;
            if (arr[r2][c2] == 1) {
                
                if (foo==1 && !visited[r2][c2][0]) {
                    visited[r2][c2][0] = true;
                    q.push({ r2, c2, d + 1, 0 });
                }
                continue;
            }
            if (!visited[r2][c2][foo]) {
                visited[r2][c2][foo] = true;
                q.push({ r2, c2, d + 1, foo });
            }
        }
    }
    if (r == n && c == m) {
        cout << d;
    }
    else cout << "-1";
}