#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;


int parent[1010];

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
    int i, j, x, y, sum, testn, n, m;
    cin >> testn;
    while (testn--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            parent[i] = i;
        }
        sum = 0;
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            if (!sameparent(x, y)) {
                sum++;
                unionn(x, y);
            }
        }
        cout << sum << "\n";
    }
    
}