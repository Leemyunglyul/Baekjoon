#include <iostream>
#include<cmath>
#include <vector>
#include <tuple>
#include <map>
#include<algorithm>
#include<queue>

using namespace std;

int today = 0;
int land[25][25], n, pass;
int fuel, carx, cary;
map<pair<int, int>, pair<int, int>> dict;

bool find_guest() {
    queue<tuple<int, int, int>> q;
    bool visited[25][25];
    fill_n(&visited[0][0], 25 * 25, false);
    visited[carx][cary] = true;
    q.push({ carx, cary, 0 });
    int lim = 500;

    
    vector<pair<int, int>> temp;

    while (!q.empty()) {
        int r = get<0>(q.front());
        int c= get<1>(q.front());
        int d= get<2>(q.front());
        q.pop();

        if (lim==500 && land[r][c] == 2) {
            lim = d;
            temp.push_back({ r, c });
            continue;
        }
        else if (d == lim && land[r][c]==2) {
            temp.push_back({ r, c });
            continue;
        }

        if (r > 1 && !visited[r - 1][c] && land[r-1][c]!=1) {
            visited[r - 1][c] = true;
            q.push({ r - 1, c, d + 1 });
        }
        if (c > 1 && !visited[r][c - 1] && land[r][c - 1] != 1) {
            visited[r][c-1] = true;
            q.push({ r , c-1, d + 1 });
        }
        if (r <n && !visited[r + 1][c] && land[r + 1][c] != 1) {
            visited[r + 1][c] = true;
            q.push({ r + 1, c, d + 1 });
        }
        if (c < n && !visited[r][c+1] && land[r][c+1] != 1) {
            visited[r][c+1] = true;
            q.push({ r, c+1, d + 1 });
        }
    }
    if (temp.empty()) return false;

    sort(temp.begin(), temp.end());
    carx = temp[0].first; 
    cary = temp[0].second;
    
    if (fuel >= lim) {
        fuel -= lim;
        return true;
    }
    else return false;
}

bool move() {
    int dr = dict[{carx, cary}].first;
    int dc= dict[{carx, cary}].second;
    land[carx][cary] = 0;
    int r, c, d;

    queue<tuple<int, int, int>> q;
    bool visited[25][25];
    fill_n(&visited[0][0], 25 * 25, false);
    q.push({ carx, cary, 0 });
    visited[carx][cary] = true;
    while (!q.empty()) {
        r = get<0>(q.front());
        c = get<1>(q.front());
        d = get<2>(q.front());
        q.pop();

        if (r == dr && c == dc) break;

        if (r > 1 && !visited[r - 1][c] && land[r - 1][c] != 1) {
            visited[r - 1][c] = true;
            q.push({ r - 1, c, d + 1 });
        }
        if (c > 1 && !visited[r][c - 1] && land[r][c - 1] != 1) {
            visited[r][c - 1] = true;
            q.push({ r , c - 1, d + 1 });
        }
        if (r < n && !visited[r + 1][c] && land[r + 1][c] != 1) {
            visited[r + 1][c] = true;
            q.push({ r + 1, c, d + 1 });
        }
        if (c < n && !visited[r][c + 1] && land[r][c + 1] != 1) {
            visited[r][c + 1] = true;
            q.push({ r, c + 1, d + 1 });
        }
    }
    if (!(r == dr && c == dc)) {
        return false;
    }
    carx = dr;
    cary = dc;
    if (fuel >= d) {
        fuel += d;
        today++;
        return true;
    }
    else return false;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> pass >> fuel;
    int i, j, x1, x2, y1, y2;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> land[i][j];
        }
    }
    cin >> carx >> cary;
    for (i = 0; i < pass; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        land[x1][y1] = 2;
        dict.insert({ { x1, y1 }, {x2, y2} });
    }

    while (today < pass) {
        if (!find_guest()) {
            cout << "-1";
            return 0;
        }
        if (!move()) {
            cout << "-1";
            return 0;
        }
        //cout << fuel << endl;
    }
    cout << fuel;
}
