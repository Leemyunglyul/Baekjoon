#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

vector<pair<int, int>> edge[1010];
int n, m, k;
priority_queue<int> dp[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int i, j, x, y, z;
    cin>>n>>m>>k;    
    for(i=1;i<=m;i++){
        cin>>x>>y>>z;
        edge[x].push_back({y, z});
    }
    
    pq.push({0, 1});
    dp[1].push(0);
    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=pq.top().first;
        pq.pop();

        for(i=0;i<edge[cur].size();i++){
            int nextt=edge[cur][i].first;
            int ccost=edge[cur][i].second;
            if(dp[nextt].size()>=k){
                if(dp[nextt].top()<=ccost+cost) continue;
                dp[nextt].pop();
            }
            dp[nextt].push(ccost+cost);
            pq.push({ccost+cost, nextt});
        }
    }
    for(i=1;i<=n;i++){
        if(dp[i].size()<k) cout<<"-1\n";
        else cout<<dp[i].top()<<"\n";
    }
}