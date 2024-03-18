#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include<algorithm>
#include<queue>

using namespace std;

int w[30][30], n, sr, sc;
pair<int, int> shark = { 2, 0 };
int Time = 0;


void sizeup() {
    shark.second++;
    if (shark.second == shark.first) {
        shark.second = 0;
        shark.first++;
    }
}

bool bfs() {
    queue<tuple<int, int, int>> q;
    q.push({ sr, sc, 0 });
    bool visited[30][30];
    fill_n(&visited[0][0], 30 * 30, false);
    visited[sr][sc] = true;
    int lim = 400;
    vector<pair<int, int>> temp;

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int tt= get<2>(q.front());
        q.pop();

        //끝물
        if (tt == lim && shark.first > w[x][y] && w[x][y]>0) {
            temp.push_back({ x, y });
            continue;
        }
        if (lim==400 && w[x][y] > 0 && shark.first>w[x][y]) {
            lim = tt;
            temp.push_back({ x, y });
            continue;
        }
        
        if (x > 1 && !visited[x - 1][y] && shark.first>=w[x-1][y]) {
            visited[x - 1][y] = true;
            q.push({ x - 1, y, tt + 1 });
        }
        if (y > 1 && !visited[x][y-1] && shark.first >= w[x][y-1]) {
            visited[x ][y-1] = true;
            q.push({ x , y-1, tt + 1 });
        }
        if (x < n && !visited[x + 1][y] && shark.first >= w[x+1][y]) {
            visited[x + 1][y] = true;
            q.push({ x + 1, y, tt + 1 });
        }
        if (y < n && !visited[x][y+1] && shark.first >= w[x][y+1]) {
            visited[x][y+1] = true;
            q.push({ x, y+1, tt + 1 });
        }
    }
    if (temp.empty()) return false;

    sort(temp.begin(), temp.end());

    Time += lim;
    sr = temp[0].first;
    sc = temp[0].second;
    int big = w[sr][sc];
    w[sr][sc] = 0;
    sizeup();

    return true;
}

void print() {
    int i, j;
    cout << Time << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << w[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j<= n; j++) {
            cin >> w[i][j];
            if (w[i][j] == 9) {
                sr = i; sc = j;
                w[i][j] = 0;
            }
        }
    }
    while (bfs()) {
      //  cout << Time<<"//"<<shark.first << endl;
       // print();
    }
    cout << Time;
}
