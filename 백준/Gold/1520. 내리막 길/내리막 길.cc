#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int n, m;
int arr[510][510];
int visited[510][510];
bool cant[510][510];
long long dp[510][510] = { 0 };
int rm[4] = { -1, 0, 1, 0 };
int cm[4] = { 0, 1, 0, -1 };

void dfs_(int r, int c) {
    int i;
    for (i = 0; i <= 3; i++) {
        int rr = r + rm[i];
        int cc = c + cm[i];
        if (rr<1 || cc<1 || rr>n || cc>m) continue;
        if (!cant[rr][cc] && arr[rr][cc]<arr[r][c]) {
            cant[rr][cc] = true;
            dfs_(rr, cc);
        }
    }
}

void dfs(int r, int c) {
    int i;
    visited[r][c] = 0;
   //cout << r << " " << c << endl;
    for (i = 0; i <= 3; i++) {
        int rr = r + rm[i];
        int cc = c + cm[i];
        if (rr<1 || cc<1 || rr>n || cc>m) continue;
        if (arr[rr][cc]<arr[r][c] && visited[rr][cc] > 0) {
            dp[rr][cc] += dp[r][c];
            visited[rr][cc]--;
        }
        if (visited[rr][cc]==1) {
            dfs(rr, cc);
        }
    }
}

void print() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cout <<dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    fill_n(&cant[0][0], 510 * 510, false);
    cant[1][1] = true;
    dfs_(1, 1);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (!cant[i][j]) continue;
            int temp = arr[i][j];
            visited[i][j] = 1;
            if (i > 1 && arr[i - 1][j] > temp && cant[i - 1][j]) visited[i][j]++;
            if (j > 1 && arr[i][j-1] > temp && cant[i][j-1]) visited[i][j]++;
            if (i < n && arr[i + 1][j] > temp && cant[i + 1][j]) visited[i][j]++;
            if (j <m && arr[i][j + 1] > temp && cant[i][j + 1]) visited[i][j]++;
        }
    }
    dp[1][1] = 1;
    dfs(1, 1);
    //cout << endl;
   // print();
    cout << dp[n][m];

    return 0;
}