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
int edge[200100][3];
int parent[200100];
priority_queue<pair<int, int>> pq;

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
    int i, j, x, y, sum;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (i = 1; i <= m; i++) {
            cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
            pq.push({ -edge[i][2] ,i });
        }
        sum = 0;
        while (!pq.empty()) {
            int d = -pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            x = edge[idx][0];
            y = edge[idx][1];
            if (!sameparent(x, y)) {
                unionn(x, y);
            }
            else sum += d;
        }
        cout << sum << "\n";
    }
    
}