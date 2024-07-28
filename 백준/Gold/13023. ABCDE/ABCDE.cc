#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

vector<int> rel[2010];
bool visited[2010];
int n;

bool check(int x, int y) {
    if (y == 5) return true;
    int i;
    for (i =0; i<rel[x].size(); i++) {
        if (visited[rel[x][i]]) continue;
        visited[rel[x][i]] = true;
        if (check(rel[x][i], y + 1)) return true;
        visited[rel[x][i]] = false;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int m, i, j, x, y;
    fill_n(&visited[0], 2010, false);
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        rel[x].push_back(y);
        rel[y].push_back(x);
    }
    for (i = 0; i <= n - 1; i++) {
        visited[i] = true;
        if (check(i, 1)) {
            cout << "1";
            return 0;
        }
        visited[i] = false;
    }
    cout << "0";
}