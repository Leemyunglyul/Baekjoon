#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int arr[1010][1010];
int t[1010][1010];
queue<tuple<int, int, int, int>> q;
queue<tuple<int, int, int, int>> temp;
bool visited[1010][1010];
int n, m;

void bfs() {
    while (!q.empty()) {
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int idx = get<2>(q.front());
        int tt = get<3>(q.front());
        q.pop();

        if (r > 1 && !visited[r - 1][c]) {
            visited[r - 1][c] = true;
            arr[r - 1][c] = idx;
            t[r - 1][c] = tt + 1;
            temp.push({ r - 1, c, idx, tt+1 });
        }
        else if (r > 1 && t[r-1][c]==tt+1 && visited[r-1][c]) {
            if (arr[r - 1][c] == 2 && idx == 1) arr[r - 1][c] = 3;
            else if (arr[r - 1][c] == 1 && idx == 2) arr[r - 1][c] = 3;
        }
        if (c > 1 && !visited[r][c-1]) {
            visited[r ][c-1] = true;
            arr[r ][c-1] = idx;
            t[r][c-1] = tt + 1;
            temp.push({ r , c-1, idx, tt+1 });
        }
        else if (c > 1 && t[r][c-1] == tt + 1 && visited[r][c-1]) {
            if(arr[r][c-1]==2 && idx==1) arr[r][c - 1] = 3;
            else if (arr[r][c - 1] == 1 && idx == 2) arr[r][c - 1] = 3;
        }
        if (r < n && !visited[r + 1][c]) {
            visited[r + 1][c] = true;
            arr[r + 1][c] = idx;
            t[r + 1][c] = tt + 1;
            temp.push({ r + 1, c, idx, tt+1 });
        }
        else if (r < n && t[r+1][c] == tt + 1 && visited[r +1][c]) {
            if (arr[r+1][c] == 2 && idx == 1) arr[r+1][c] = 3;
            else if (arr[r+1][c] == 1 && idx == 2) arr[r+1][c] = 3;
        }
        if (c <m && !visited[r][c + 1]) {
            visited[r][c + 1] = true;
            arr[r][c + 1] = idx;
            t[r][c+1] = tt + 1;
            temp.push({ r , c + 1, idx, tt+1 });
        }
        else if (c < m &&  t[r][c+1] == tt + 1 && visited[r][c+1]) {
            if (arr[r][c +1] == 2 && idx == 1) arr[r][c + 1] = 3;
            else if (arr[r][c +1] == 1 && idx == 2) arr[r][c + 1] = 3;
        }
    }
    int i, j;
    /*cout << "&&&&&&&&&&7\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "&&---------\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }*/
    if (temp.empty()) return;
    else {
        while (!temp.empty()) {
            int r = get<0>(temp.front());
            int c = get<1>(temp.front());
            if (arr[r][c] == 3) {
                temp.pop();
                continue;
            }
            q.push({temp.front()});
            temp.pop();
        }
        bfs();
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int i, j;
    cin >> n >> m;
    fill_n(&visited[0][0], 1010 * 1010, false);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i, j, 1, 0 });
                visited[i][j] = true;
            }
            else if (arr[i][j] == 2) {
                q.push({ i, j, 2, 0 });
                visited[i][j] = true;
            }
            else if (arr[i][j] == -1) {
                visited[i][j] = true;
            }
        }
    }
    bfs();
    /*for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    int a1 = 0; int a2 = 0; int a3 = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                a1++;
            }
            else if (arr[i][j] == 2) {
                a2++;
            }
            else if (arr[i][j] == 3) {
                a3++;
            }
        }
    }
    cout << a1 << " " << a2 << " " << a3;
    return 0;
}