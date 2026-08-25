#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int v, e;
int num[1010];
vector<int> adj[1010];
queue<int> q;
queue<int> ans;

void solve(){
    for(int i = 1; i <= v; i++){
        if(num[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.push(now);

        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i];
            num[next]--;
            if(num[next] == 0) q.push(next);
        }
    }

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    cout<< "\n";
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> v >> e;
        int f, s;
        fill_n(num, 1010, 0);
        for(int i = 0; i < 1010; i++) adj[i].clear();
        for (int i = 0; i < e; i++) {
            cin >> f >> s;
            num[s]++;
            adj[f].push_back(s);
        }  
        cout<< "#" << test_case << " ";
        solve();
    }

    return 0;
}