#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int dp[110][2];
int list[110];//도착, 피로, 비용
bool reach[110][110];
int big=987654321;
vector<tuple<int, int, int>> edge[110];

bool check(int n, int s, int e){
    int i, j, k, x, y, a, b;   
    for(j=0;j<=n-1;j++){
        for(k=0;k<edge[j].size();k++){
            x=j;
            y=get<0>(edge[j][k]);
            a=get<1>(edge[j][k]);
            b=get<2>(edge[j][k]);
            if(dp[x][0]>=big) continue;
            if(dp[x][0]+a<dp[y][0] || (dp[x][0]+a==dp[y][0] && dp[x][1]+b<dp[y][1])){
                dp[y][0]=dp[x][0]+a;
                dp[y][1]=dp[x][1]+b;
               // cout<<x<<"-"<<y<<"//////\n";
                if(reach[s][y] && reach[y][e]) return false;
            }
        }
            
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill_n(&reach[0][0], 110*110, false);
    fill_n(&list[0], 110, big);
    fill_n(&dp[0][0],110*2, big);
    int n, m, s, e, i, j, k, x,y, a, b, c;
    cin>>n>>m>>s>>e;
    for(i=1;i<=m;i++){
        cin>>x>>y>>a>>c>>b;
        if(list[x]==big || list[x]>a ){
            edge[x].clear();
            list[x]=a;
            edge[x].push_back({y, a, c});
        }
        else if(list[x]==a) edge[x].push_back({y, a, c});
        if(list[y]==big || list[y]>b ){
            edge[y].clear();
            list[y]=b;
            edge[y].push_back({x, b, c});
        }
        else if(list[y]==b) edge[y].push_back({x, b, c});
    }
    dp[s][0]=0; dp[s][1]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<=n-1;j++){
            for(k=0;k<edge[j].size();k++){
                x=j;
                y=get<0>(edge[j][k]);
                a=get<1>(edge[j][k]);
                b=get<2>(edge[j][k]);
                if(dp[x][0]>=big) continue;
                if(dp[x][0]+a<dp[y][0] || (dp[x][0]+a==dp[y][0] && dp[x][1]+b<dp[y][1])){
                    dp[y][0]=dp[x][0]+a;
                    dp[y][1]=dp[x][1]+b;
                }
            }
            
        }
    }
    for(j=0;j<=n-1;j++){
        for(k=0;k<edge[j].size();k++){
            x=j;
            y=get<0>(edge[j][k]);
            a=get<1>(edge[j][k]);
            b=get<2>(edge[j][k]);
            //cout<<x<<"->"<<y<<endl;
            reach[x][y]=true;
        }
            
    }
    bool cc=false&&true;
   // cout<<cc<<"------\n ";
    for(k=0;k<n;k++){
        for(j=0;j<n;j++){
            for(i=0;i<n;i++){
                reach[i][j]|=reach[i][k]&&reach[k][j];
            }
            //cout<<i<<"~"<<j<<"=="<<reach[i][j]<<endl;
        }
    }
    if(dp[e][0]>=big){
        cout<<"VOID";
        return 0;
    }
    if(!check(n, s, e)){
        cout<<"UNBOUND";
        return 0;
    }
    cout<<dp[e][0]<<" "<<dp[e][1];
}
