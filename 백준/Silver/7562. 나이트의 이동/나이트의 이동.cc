#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

bool arr[310][310];
queue<tuple<int, int, int>> q;
int m1[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int m2[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, n, i, x, y, s, e, num;

    cin >> testn;
    while (testn--) {
        cin >> n;
        cin >> x >> y;
        cin >> s >> e;
        fill_n(&arr[0][0], 310 * 310, false);
        q.push({ x, y, 0 });
        arr[x][y] = true;
        while (!q.empty()) {
            int r = get<0>(q.front());
            int c = get<1>(q.front());
            num= get<2>(q.front());
            q.pop();
            if (r == s && c == e) break;

            for (i = 0; i <= 7; i++) {
                int r2 = r + m1[i];
                int c2 = c + m2[i];

                if (r2<0 || r2>n - 1 || c2<0 || c2>n - 1) continue;

                if (!arr[r2][c2]) {
                    arr[r2][c2] = true;
                    q.push({ r2, c2, num + 1 });
                }
            }
        }
        while (!q.empty()) q.pop();
        cout << num << "\n";
    }
}