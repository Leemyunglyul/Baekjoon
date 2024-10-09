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
#include <unordered_map>
typedef long long ll;

using namespace std;

int club[1001000];
int num[1001000];
int team[1001000];
int edge[1001000][2];

int find(int x){
    if(team[x]==x) return x;
    else return team[x]=find(team[x]);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    if(club[x]!=club[y] || team[x]==team[y]) return;
    team[y]=x;
    num[x]+=num[y];
}

int track(int x, int k){
    if(edge[x][k]==x) return x;
    else return edge[x][k]=track(edge[x][k], k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, i,k, x, y, sum, a, b,m;
    cin>>k>>n;
    edge[n+1][0]=n+1;
    edge[n+1][1]=n+1;
    for(i=1, sum=0;i<=n;i++){
        cin>>club[i];
        team[i]=i;
        num[i]=1;
        edge[i][0]=i;
        edge[i][1]=i;
    }
    for(i=2;i<=n;i++){
        unionn(i, i-1);
    }
    cin>>m;
    while(m--){
        cin>>x>>y;
        if(x==1){
            num[find(y)]--;
            edge[y][0]=track(edge[y-1][0], 0);
            edge[y][1]=track(edge[y+1][1], 1);
            unionn(edge[y][0], edge[y][1]);
        }
        else{
            sum+=num[find(y)];
        }
    }
    cout<<sum;
}
