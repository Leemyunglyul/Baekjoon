#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> edge[10010];
vector<pair<int, bool>> rev[10010];
int arr[10010];
int dp[10010][2] = { 0 };
bool visited[10010];
vector<int> print;
//0: 포함X, 1: 포함

void dfs(int now) {
    int i;
    for (i = 0; i < edge[now].size(); i++) {
        if (!visited[edge[now][i]]) {
            visited[edge[now][i]] = true;
            dfs(edge[now][i]);
            dp[now][1] += dp[edge[now][i]][0];
            dp[now][0] += max(dp[edge[now][i]][1], dp[edge[now][i]][0]);
            if (dp[edge[now][i]][0] < dp[edge[now][i]][1]) {
                rev[now].push_back({ edge[now][i], true });
            }
            else rev[now].push_back({ edge[now][i], false });
        }
    }
    dp[now][1] += arr[now];
    //cout << now << ":" << dp[now][0] << " " << dp[now][1] << endl;
}

void track(int now, bool pos) {
    int i;
    for (i = 0; i < rev[now].size(); i++) {
        if (pos) {
            track(rev[now][i].first, false);
        }
        else {
            if(rev[now][i].second) print.push_back(rev[now][i].first);
            track(rev[now][i].first, rev[now][i].second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, x, y;
    cin >> n;
    fill_n(&visited[0], 10010, false);
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    visited[1] = true;
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
   // fill_n(&visited[0], 10010, false);
    if (dp[1][0] < dp[1][1]) {
        print.push_back(1);
        track(1, true);
    }
    else {
        track(1, false);
    }
    sort(print.begin(), print.end());
    for (i = 0; i < print.size(); i++) cout << print[i] << " ";
}