#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

vector<int> edge[32010];
int arr[32010];
vector<int> result;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n, m, i, j, x, y;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        arr[y]++;
    }
    for (i = 1; i <= n; i++) {
        if (arr[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        x = q.front();
        result.push_back(x);
        q.pop();
        for (i = 0; i < edge[x].size(); i++) {
            arr[edge[x][i]]--;
            if (arr[edge[x][i]] == 0) q.push(edge[x][i]);
        }
    }
    for (i = 0; i < result.size(); i++) cout << result[i] << " ";
}