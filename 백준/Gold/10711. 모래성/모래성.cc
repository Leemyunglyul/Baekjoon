#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int arr[1010][1010];
bool visited[1010][1010];
queue<tuple<int, int, int>> q;
queue<pair<int, int>> temp;
int a[8] = {-1,-1,-1,0,0,1, 1, 1};
int b[8] = {-1,0,1,-1,1,-1,0,1};
int r, c;

bool check(int x, int y) {
    int i, num, row, col;
    for (num = 0, i = 0; i < 8; i++) {
        row = x + a[i];
        col = y + b[i];
        if (row<1 || col<1 || row>r || col>c) continue;
        if (arr[row][col] == 0) num++;
    }
    if (arr[x][y] <= num) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, rr, cc;
    fill_n(&visited[0][0], 1010 * 1010, false);
    char x;
    cin >> r >> c;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            cin >> x;
            if (x == '.') {
                arr[i][j] = 0;
                q.push({ 0, i, j });
                visited[i][j] = true;
            }
            else {
                arr[i][j] = x - 48;
            }
        }
    }
    int d = 0; int pre = 0;
    while (!q.empty()) {
        int num = get<0>(q.front());
        if (pre != num) {
            while (!temp.empty()) {
                arr[temp.front().first][temp.front().second] = 0;
                temp.pop();
            }
        }
        int row= get<1>(q.front());
        int col = get<2>(q.front());
        d = max(d, num);
        q.pop();
        
        for (i = 0; i < 8; i++) {
            rr = row + a[i];
            cc = col + b[i];
            if (rr<1 || cc<1 || rr>r || cc>c || visited[rr][cc]) continue;
            if (check(rr, cc) && arr[rr][cc]!=0) {
                //arr[rr][cc] = 0;
                q.push({ num + 1, rr, cc });
                visited[rr][cc] = true;
                temp.push({ rr, cc });
            }
        }
        pre = num;
    }
    cout << d;
    /*for (i = 1, cout << endl; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }*/
}