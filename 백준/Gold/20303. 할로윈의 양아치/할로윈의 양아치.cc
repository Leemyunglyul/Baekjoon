#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int candy[30010];

int tree[30010];

map<int, pair<int, int>> mp;
vector<pair<int, int>> v;  

int find(int x){
    if(tree[x]==x) return x;
    return tree[x]=find(tree[x]);
}

void unionn(int x, int y){
    int a=find(x);
    int b=find(y);
    if(a!=b){
        tree[b]=a;
    }
}

bool samep(int x, int y){
    return find(x)==find(y);
}

int backpack(int W, int N){
    vector<int> dp(30010, 0);

    for(int i=0;i<N;i++){
        int weight = v[i].first;
        int value = v[i].second;
        
        for(int w=W;w>=weight;w--){
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    }

    int anw=0;

    for(int i=0;i<=W;i++){
        anw=max(anw, dp[i]);
    }
    return anw;
}

void solve(){

    int n, m, k, i, j, a, b;

    cin >> n >> m >> k;

    for(i=1;i<=n;i++){
        cin>>candy[i];
        tree[i]=i;
    }

    for(i=1;i<=m;i++){
        cin >> a >> b;
        unionn(a, b);
    }

    for(i=1;i<=n;i++){
        mp[find(i)].first += candy[i];
        mp[find(i)].second += 1;
    }

    // vector: 사람 명수, 사탕 갯수
    for(auto it = mp.begin(); it != mp.end(); it++){
        v.push_back({it->second.second, it->second.first});
    }

    // k: 
    cout << backpack(k-1, v.size()) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}


