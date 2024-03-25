#include <iostream>
#include <map>
#include <vector>
typedef long long ll;

using namespace std;

bool visited[10010];
vector<ll> edge[10010];
map<pair<ll, ll>, ll> w;//입력
ll dp[10010][2] = {0};//점의 갯수, 총 거리
ll big = 98765421987654321;
ll n;

pair<ll, ll> dfs(ll now) {
    pair<ll, ll> temp = {0, 0};
    visited[now] = true;

    for (ll i = 0; i < edge[now].size(); i++) {
        if (visited[edge[now][i]]) continue;

        temp = dfs(edge[now][i]);
        dp[now][0] += temp.first;
        dp[now][1] += temp.first * w[{now, edge[now][i]}]+temp.second;
    }
    return { dp[now][0], dp[now][1] };
}

void dfs2(ll now,  ll dis) {
    visited[now] = true;
    dp[now][0] = n;
    dp[now][1] += dis;
    big = min(dp[now][1], big);
    for (ll i = 0; i < edge[now].size(); i++) {
        if (visited[edge[now][i]]) continue;
        dfs2(edge[now][i], dp[now][1] - dp[edge[now][i]][1] + (n - 2 * dp[edge[now][i]][0]) * w[{now, edge[now][i]}]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll i, x, y, w2;
    while (1) {
        cin >> n;
        if (n == 0) return 0;
        for (i = 1; i <= n-1; i++) {
            cin >> x >> y >> w2;
            w.insert({ {x, y}, w2 });
            w.insert({ {y, x}, w2 });

            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        for (i = 0, x=0; i <= n-1; i++) {
            dp[i][0] = 1;
            dp[i][1] = 0;
            if (edge[i].size() == 1) x = i;
        }
        fill_n(&visited[0], 10010,false);
        if(n>1) dfs(x);

        fill_n(&visited[0], 10010, false);
        big = min(dp[x][1], big);
        visited[x] = true;
        if (n > 1) dfs2(edge[x][0], w[{x, edge[x][0]}]);
       
        cout << big << "\n";
        big= 98765421987654321;
        for (i = 0; i <= n - 1; i++) {
            edge[i].clear();
        }
        w.clear();  
    }
    
}
