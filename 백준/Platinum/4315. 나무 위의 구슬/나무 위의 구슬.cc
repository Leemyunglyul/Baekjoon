#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> edge[10010];
int arr[10010];
long long sum = 0;
bool visited[10010];

long long dfs(int now) {
    if (edge[now].empty()) {
        sum += abs(arr[now] - 1);
        return arr[now] - 1;
    }
    int i;
    long long temp = 0;
    for (i = 0; i < edge[now].size(); i++) {
        temp += dfs(edge[now][i]);
    }
    sum += abs(arr[now] + temp-1);
    return (arr[now] + temp - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, n, i, j, nn, x, y;
    while (1) {
        cin >> n;
        if (n == 0) return 0;
        fill_n(&visited[0], 10010, false);
        for (i = 1, sum = 0; i <= n; i++) {
            cin >> y;
            cin>>arr[y] >> nn;
            edge[y].clear();
            for (j = 1; j <= nn; j++) {
                cin >> x;
                edge[y].push_back(x);
                visited[x] = true;
            }
        }
        for (i = 1; i <= n; i++) {
            if (!visited[i]) break;
        }
        dfs(i);
        cout << sum << "\n";
    }

    return 0;
}