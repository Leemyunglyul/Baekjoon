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

vector<pair<int, int>> edge[10010];
ll dp[12][10010];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
int check[12];
ll big=211987654321;
ll n, m;

void dijkstra(int s){
    int x=check[s];
    int i, j;
    dp[s][x]=0;
    pq.push({dp[s][x], x});
    while(!pq.empty()){
        ll cur=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        if(dp[s][cur]!=cost) continue;
        for(i=0;i<edge[cur].size();i++){
            ll nextt=edge[cur][i].first;
            ll ccost=edge[cur][i].second;
            if(dp[s][nextt]>cost+ccost){
                dp[s][nextt]=cost+ccost;
                pq.push({dp[s][nextt], nextt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll i, j, x,y,z, start, end;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>x>>y>>z;
        edge[x].push_back({y, z});
        edge[y].push_back({x, z});
    }
    for(i=1;i<=10;i++) cin>>check[i];
    cin>>check[11];
    fill_n(&dp[0][0], 12*10010, big);
    for(i=1;i<=11;i++) dijkstra(i);
    ll sum=0;
    int anw=n+1;
    if(check[11]==check[1]){
        anw=check[1];
    }
    for(i=1;i<=9;i++){
        end=i+1;
        //cout<<i<<"---->"<<end<<endl;
        ll d=dp[i][check[end]];
        while(d==big && end<=10){
            d=dp[i][check[++end]];
           // cout<<i<<"->"<<end<<"=="<<d<<endl;
        }
        if(end>10) break;    
        sum+=d;
        if(sum>=dp[11][check[end]]){
            anw=min(anw, check[end]);
        }
        i=end-1;
       // cout<<i<<"---->"<<end<<endl;
    }
    if(anw==n+1)cout<<"-1";
    else cout<<anw;
}