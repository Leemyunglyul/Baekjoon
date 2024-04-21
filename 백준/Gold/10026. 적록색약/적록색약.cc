#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int arr[110][110], n;
bool visited[110][110];

void bfs(int i, int j) {
    
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({ i, j });
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        int idx = arr[r][c];
        q.pop();

        if (r > 1 && !visited[r - 1][c] && arr[r-1][c]==idx) {
            visited[r - 1][c] = true;
            q.push({ r - 1, c });
        }
        if (c > 1 && !visited[r][c-1] && arr[r][c-1] == idx) {
            visited[r][c-1] = true;
            q.push({ r, c-1 });
        }
        if (r <n && !visited[r + 1][c] && arr[r + 1][c] == idx) {
            visited[r + 1][c] = true;
            q.push({ r + 1, c });
        }
        if (c <n && !visited[r][c + 1] && arr[r][c+1] == idx) {
            visited[r][c + 1] = true;
            q.push({ r, c + 1 });
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    int i, j;
    char x;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> x;
            if (x == 'R') {
                arr[i][j] = 1;
            }
            else if (x == 'G') {
                arr[i][j] = 2;
            }
            else if (x == 'B') {
                arr[i][j] = 3;
            }
        }
    }
    fill_n(&visited[0][0], 110 * 110, false);
    int a1 = 0; int a2 = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                a1++;
                bfs(i, j);
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (arr[i][j] == 2) arr[i][j] = 1;
        }
    }
    fill_n(&visited[0][0], 110 * 110, false);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                a2++;
                bfs(i, j);
            }
        }
    }
    cout << a1 << " " << a2;

    return 0;
}