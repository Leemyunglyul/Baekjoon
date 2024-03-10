#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

int room[30][30] = { 0 };
int temp[30][30], row, col, tt, walln;
int wall[30][30][5] = {0};  //상에서 시계방향
bool visited[30][30];
bool vit[500][23][23];
//1오른2왼3위4아래
vector<tuple<int, int, int>> hot;
vector<pair<int, int>> to_check;

void bfs() {
    fill_n(&vit[0][0][0], 500 * 23 * 23, false);
    queue<tuple<int, int, int, int, int>> q;
    int i, r, c, d, tems, num;
    for (i = 0; i < hot.size(); i++) {
        r = get<0>(hot[i]);
        c = get<1>(hot[i]);
        d = get<2>(hot[i]);
        if (d == 1 && r > 1 ) q.push({ r - 1, c, d, 5, i });
        else if (d == 2 && c < col ) q.push({ r, c + 1, d, 5, i });
        else if (d == 3 && r < row ) q.push({ r + 1, c, d, 5, i });
        else if (d == 4 && c > 1) q.push({ r, c - 1, d, 5, i });
        vit[i][r][c] = true;
    }

    while (!q.empty()) {
        r = get<0>(q.front());
        c = get<1>(q.front());
        d = get<2>(q.front());
        tems = get<3>(q.front());
        num = get<4>(q.front());
        room[r][c] += tems;
        q.pop();
        //위로
        if (d == 1 && r > 1) {
            if (c > 1 && !vit[num][r-1][c-1]&&  (/*(wall[r][c][1] == 0 && wall[r - 1][c][4] == 0)||*/
                (wall[r][c][4]==0 && wall[r][c-1][1]==0))) {
                //room[r - 1][c - 1] += tems;
                vit[num][r - 1][c - 1] = true;
                if (tems > 1) {
                    q.push({ r - 1, c - 1, d, tems - 1, num });
                }
            }
            if (wall[r][c][1] == 0 && !vit[num][r-1][c]) {
               // room[r - 1][c ] += tems;
                vit[num][r - 1][c] = true;
                if (tems > 1) q.push({ r - 1, c, d, tems - 1, num });
            }
            if (c <col && !vit[num][r-1][c+1] && (/*(wall[r][c][1] == 0 && wall[r - 1][c][2] == 0)
                ||*/ (wall[r][c][2] == 0 && wall[r][c + 1][1] == 0))) {
                //room[r - 1][c + 1] += tems;
                vit[num][r - 1][c + 1] = true;
                if (tems > 1) q.push({ r - 1, c + 1, d, tems - 1, num });
            }
        }
        if (d == 2 && c<col) {//오른쪽
            if (r > 1 && !vit[num][r-1][c+1] && (/*(wall[r][c][2] == 0 && wall[r][c + 1][1] == 0)
                ||*/ (wall[r][c][1] == 0 && wall[r-1][c][2] == 0))) {
                //room[r - 1][c + 1] += tems;
                vit[num][r - 1][c + 1] = true;
                if (tems > 1) q.push({ r - 1, c + 1, d, tems - 1,num });
            }
            if (wall[r][c][2] == 0 && !vit[num][r][c + 1]) {
                //room[r][c+1] += tems;
                vit[num][r][c + 1] = true;
                if (tems > 1) q.push({ r , c+1, d, tems - 1, num });
            }
            if (r<row && !vit[num][r+1][c + 1] && (/*(wall[r][c][2] == 0 && wall[r][c + 1][3] == 0)
                ||*/ (wall[r][c][3] == 0 && wall[r+1][c][2] == 0))) {
                //room[r + 1][c + 1] += tems;
                vit[num][r+1][c + 1] = true;
                if (tems > 1) q.push({ r + 1, c + 1, d, tems - 1, num });
            }
        }
        if (d == 3 && r <row) {
            if (c > 1 && !vit[num][r + 1][c -1] && (/*(wall[r][c][3] == 0 && wall[r + 1][c][4] == 0)
                ||*/ (wall[r][c][4] == 0 && wall[r][c-1][3] == 0))) {
                //room[r + 1][c - 1] += tems;
                vit[num][r+1][c- 1] = true;
                if (tems > 1) q.push({ r + 1, c - 1, d, tems - 1, num });
            }
            if (wall[r][c][3] == 0 && !vit[num][r + 1][c]) {
                //room[r + 1][c] += tems;
                vit[num][r + 1][c] = true;
                if (tems > 1) q.push({ r + 1, c, d, tems - 1, num });
            }
            if (c < col && !vit[num][r + 1][c + 1] && (/*(wall[r][c][3] == 0 && wall[r - 1][c][2] == 0)
                ||*/ (wall[r][c][2] == 0 && wall[r][c + 1][3] == 0))) {
                //room[r + 1][c + 1] += tems;
                vit[num][r + 1][c + 1] = true;
                if (tems > 1) q.push({ r + 1, c + 1, d, tems - 1, num });
            }
        }
        if (d == 4 && c >1) {//왼쪽
            if (r > 1 && !vit[num][r - 1][c - 1] && (/*(wall[r][c][4] == 0 && wall[r][c - 1][1] == 0)
                ||*/ (wall[r][c][1] == 0 && wall[r - 1][c][4] == 0))) {
                //room[r - 1][c - 1] += tems;
                vit[num][r - 1][c - 1] = true;
                if (tems > 1) q.push({ r - 1, c - 1, d, tems - 1, num });
            }
            if (wall[r][c][4] == 0 && !vit[num][r][c - 1]) {
                //room[r][c - 1] += tems;
                vit[num][r ][c - 1] = true;
                if (tems > 1) q.push({ r , c - 1, d, tems - 1 , num });
            }
            if (r < row && !vit[num][r +1][c - 1] && (/*(wall[r][c][4] == 0 && wall[r][c - 1][2] == 0)
                ||*/ (wall[r][c][3] == 0 && wall[r + 1][c][4] == 0))) {
                //room[r + 1][c - 1] += tems;
                vit[num][r + 1][c - 1] = true;
                if (tems > 1) q.push({ r + 1, c - 1, d, tems - 1 , num });
            }
        }
    }
}

void mix() {
    int i, j, diff;
    fill_n(&visited[0][0], 30 * 30, false);
    fill_n(&temp[0][0], 30 * 30, 0);
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            visited[i][j] = true;
            if (i > 1 && !visited[i - 1][j] && wall[i][j][1] == 0) {
                diff = abs(room[i - 1][j] - room[i][j])/4;
                if (room[i - 1][j] <= room[i][j]) {
                    temp[i - 1][j] += diff;
                    temp[i][j] -= diff;
                }
                else {
                    temp[i - 1][j] -= diff;
                    temp[i][j] += diff;
                }
            }
            if (i <row && !visited[i + 1][j] && wall[i][j][3] == 0) {
                diff = abs(room[i + 1][j] - room[i][j])/4;
                if (room[i + 1][j] <= room[i][j]) {
                    temp[i + 1][j] += diff;
                    temp[i][j] -= diff;
                }
                else {
                    temp[i + 1][j] -= diff;
                    temp[i][j] += diff;
                }
            }
            if (j > 1 && !visited[i][j-1] && wall[i][j][4] == 0) {
                diff = abs(room[i][j-1] - room[i][j])/4;
                if (room[i][j-1] <= room[i][j]) {
                    temp[i][j-1] += diff;
                    temp[i][j] -= diff;
                }
                else {
                    temp[i][j-1] -= diff;
                    temp[i][j] += diff;
                }
            }
            if (j <col && !visited[i][j + 1] && wall[i][j][2] == 0) {
                diff = abs(room[i][j + 1] - room[i][j])/4;
                if (room[i][j + 1] <= room[i][j]) {
                    temp[i][j + 1] += diff;
                    temp[i][j] -= diff;
                }
                else {
                    temp[i][j + 1] -= diff;
                    temp[i][j] += diff;
                }
            }
        }
    }
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            room[i][j] += temp[i][j];
        }
    }
}

//종료 확인
bool checkok() {
    for (int i = 0; i < to_check.size(); i++) {
        int r = to_check[i].first;
        int c = to_check[i].second;
        if (room[r][c] < tt) return false;
    }
    return true;
}

void outline() {
    int i, j;
    for (i = 1; i <= col; i++) {
        if (room[1][i] > 0) room[1][i]--;
    }
    for (i = 2; i < row; i++) {
        if (room[i][1] > 0) room[i][1]--;
        if (room[i][col] > 0) room[i][col]--;
    }
    for (i = 1; i <= col; i++) {
        if (room[row][i] > 0) room[row][i]--;
    }
}

void print() {
    int i, j;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            cout << room[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

int op() {
    int time = 0;
    while (!checkok()) {
        //cout << time + 1 << "번째\n";
        bfs();
        //cout << "온풍기\n";
        //print();
        mix();
        //cout << "섞\n";
        //print();
        outline();
        //cout << "업애\n";
        //print();
        time++;
        if (time > 100) return 101;
    }
    return time;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> row >> col >> tt;
    int i, j, x, r, c, d;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            cin >> x;
            
            if (x == 5) to_check.push_back({ i, j });
            else if (x > 0) {
                //1오른2왼3위4아래
                if (x == 1) x = 2;
                else if (x == 2) x = 4;
                else if (x == 3) x = 1;
                else if(x==4) x= 3;
                hot.push_back({ i, j, x });
            }
        }
    }
    cin >> walln;
    for (i = 1; i <= walln; i++) {
        cin >> r >> c >> d;
        if (d == 1) {
            wall[r][c][2] = 1;
            wall[r][c+1][4] = 1;
        }
        else {
            wall[r][c][1] = 1;
            wall[r-1][c][3] = 1;
        }
    }
    cout << op();
}
