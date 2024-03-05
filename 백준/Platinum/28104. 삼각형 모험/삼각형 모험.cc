#include <iostream>
#include<math.h>
#include<vector>
#include<map>

using namespace std;

int dir[3][5] = {//상하좌우로 N이나 Z로 접근
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},//Z
    {0, 1, 0, 0, 1}//N
};

int graph[510][510], row, col;
bool visited[510][510][2];
bool visited2[510][510][2];
map<tuple<int, int, int>, tuple<int, int, int, int>> list;
vector<tuple<int, int, int, int>> temp;

void dfs(int r, int c, int t, int num, int index) {
    visited[r][c][t] = true;
    temp.push_back({ r, c, t, num });
    if (graph[r][c] == 1) {//Z
        if (t == 0) {//위쪽(위 아니면 왼쪽)
            if (r > 1 && !visited[r - 1][c][1]) {
                dfs(r - 1, c, 1, num+1,index);
            }
            if (c > 1 && !visited[r][c - 1][dir[graph[r][c - 1]][3]]) {
                dfs(r, c - 1, dir[graph[r][c - 1]][3], num + 1, index);
            }
        }
        else {//아래쪽(아래로 아니면 오른쪽)
            if (r <row && !visited[r+ 1][c][0]) {
                dfs(r + 1, c, 0, num + 1, index);
            }
            if (c <col && !visited[r][c + 1][dir[graph[r][c + 1]][4]]) {
                dfs( r, c + 1, dir[graph[r][c + 1]][4], num + 1, index);
            }
        }
    }
    else {//N
        if (t == 0) {//위쪽(위 아니면 오른쪽)
            if (r > 1 && !visited[r - 1][c][1]) {
                dfs( r - 1, c, 1, num + 1, index);
            }
            if (c < col && !visited[r][c + 1][dir[graph[r][c + 1]][4]]) {
                dfs(r, c + 1, dir[graph[r][c + 1]][4], num + 1, index);
            }
        }
        else {//아래쪽(아래로 아니면 왼쪽)
            if (r < row && !visited[r + 1][c][0]) {
                dfs( r + 1, c, 0, num + 1, index);
            }
            if (c > 1 && !visited[r][c - 1][dir[graph[r][c - 1]][3]]) {
                dfs( r, c - 1, dir[graph[r][c - 1]][3], num + 1, index);
            }
        }
    }
}

bool cycle(int r, int c, int t) {
    if (graph[r][c] == 1) {//Z
        if (t == 0) {//위쪽(위 아니면 왼쪽)
            if (r > 1 && c>1) {
                return true;
            }
            
        }
        else {//아래쪽(아래로 아니면 오른쪽)
            if (r < row && c < col) {
                return true;
            }
        }
    }
    else {//N
        if (t == 0) {//위쪽(위 아니면 오른쪽)
            if (r > 1 && c < col) {
                return true;
            }
        }
        else {//아래쪽(아래로 아니면 왼쪽)
            if (r < row && c > 1) {
                return true;
            }
        }
    }
    return false;
}

tuple<int, int, int> find_tail(int r, int c, int t) {
    visited2[r][c][t] = true;
    if (graph[r][c] == 1) {//Z
        if (t == 0) {//위쪽(위 아니면 왼쪽)
            if (r > 1 && !visited2[r - 1][c][1]) {
                return find_tail(r - 1, c, 1);
            }
            if (c > 1 && !visited2[r][c - 1][dir[graph[r][c - 1]][3]]) {
                return find_tail(r, c - 1, dir[graph[r][c - 1]][3]);
            }
        }
        else {//아래쪽(아래로 아니면 오른쪽)
            if (r < row && !visited2[r + 1][c][0]) {
                return find_tail(r + 1, c, 0);
            }
            if (c < col && !visited2[r][c + 1][dir[graph[r][c + 1]][4]]) {
                return find_tail(r, c + 1, dir[graph[r][c + 1]][4]);
            }
        }
    }
    else {//N
        if (t == 0) {//위쪽(위 아니면 오른쪽)
            if (r > 1 && !visited2[r - 1][c][1]) {
                return find_tail(r - 1, c, 1);
            }
            if (c < col && !visited2[r][c + 1][dir[graph[r][c + 1]][4]]) {
                return find_tail(r, c + 1, dir[graph[r][c + 1]][4]);
            }
        }
        else {//아래쪽(아래로 아니면 왼쪽)
            if (r < row && !visited2[r + 1][c][0]) {
                return find_tail(r + 1, c, 0);
            }
            if (c > 1 && !visited2[r][c - 1][dir[graph[r][c - 1]][3]]) {
                return find_tail(r, c - 1, dir[graph[r][c - 1]][3]);
            }
        }
    }
    return { r, c, t };
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q, i, j, x1, y1, t1, x2, y2, t2, k, l, r, c, t, num, t3, cc;
    char x;
    cin >> row >> col>>q;
    fill_n(&visited[0][0][0], 510 * 510*2, false);
    fill_n(&visited2[0][0][0], 510 * 510 * 2, false);
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            cin >> x;
            if (x == 'Z') graph[i][j] = 1;
            else graph[i][j] = 2;
        }
    }
    int index = 1;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            for (k = 0; k <= 1; k++) {
                if (visited[i][j][k]) continue;
                tuple<int, int, int> tt = find_tail(i, j, k);
                if (cycle(get<0>(tt), get<1>(tt), get<2>(tt))) cc = 1;
                else cc = 0;
                dfs(get<0>(tt), get<1>(tt), get<2>(tt), 0, index);
                //cout << get<0>(tt) << " " << get<1>(tt) << " " << get<2>(tt) << " // " << cc << endl;
                for (l = 0; l < temp.size(); l++) {
                    r = get<0>(temp[l]);
                    c = get<1>(temp[l]);
                    t = get<2>(temp[l]);
                    num = get<3>(temp[l]);
                    list.insert({ {r, c, t},{index, num, cc , temp.size()} });
                }
                index++;
                temp.clear();
            }
        }
    }
   // cout << index << "인덱스\n";
    for (i = 1; i <= q; i++) {
        cin>> x1>> y1>> t1>> x2>> y2>> t2;
        tuple<int, int, int, int> a1 = list[{x1, y1, t1}];
        tuple<int, int, int, int> a2 = list[{x2, y2, t2}];

        if (get<0>(a1) != get<0>(a2)) cout << "-1";
        else {
            if (get<2>(a1) == 1) {
                t = abs(get<1>(a1) - get<1>(a2));
                t1 = min(get<1>(a1), get<1>(a2));
                t2 = max(get<1>(a1), get<1>(a2));
                t3 = get<3>(a1) - t2 + t1;
                cout << min(t, t3);
            }
            else {
                cout << abs(get<1>(a1) - get<1>(a2));
            }
        }
        cout << "\n";
    }
}
