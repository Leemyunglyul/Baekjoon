#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;

int n, m;
double pos[1010][2];
int parent[1010];
priority_queue<tuple<double, int, int>> pq;

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void unionn(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int i, j, x,y;
    for (i = 1; i <= n; i++) {
        parent[i] = i;
        cin >> pos[i][0] >> pos[i][1];
    }
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        unionn(x, y);
    }
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            double d = (pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) +
                (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]);
            pq.push({ -d, i, j });
        }
    }
    double anw = 0;
    while (!pq.empty()) {
        double d = -get<0>(pq.top());
        x= get<1>(pq.top());
        y = get<2>(pq.top());
        pq.pop();

        if (!sameparent(x, y)) {
            //cout << x << " " << y << endl;
            unionn(x, y);
            anw += sqrt(d);
        }
    }
    //cout << fixed;
    //cout.precision(2);
    printf("%.2f", round(anw * 100) / 100);
}