#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> arr;
int depth[100010];
int parent[100010][17];
const int MAX=17;
int n;

void dfs(int cur){
    for(int next: arr[cur]){
        if(depth[next]==-1){
            parent[next][0]=cur;
            depth[next]=depth[cur]+1;
            dfs(next);
        }
    }
}

void connection(){
    for(int k=1;k<MAX;k++){
        for(int cur=1;cur<=n;cur++){
            parent[cur][k]=parent[parent[cur][k-1]][k-1];
        }   
    }
}

int LCA(int u, int v){
    if(depth[u]<depth[v]) swap(u, v);

    int diff=depth[u]-depth[v];

    for(int i=0;diff!=0;i++){
        if(diff%2==1)
            u=parent[u][i];
        
        diff/=2;
    }

    if(u!=v){
        for(int i=MAX-1;i>=0;i--){
            if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i]){
                u=parent[u][i];
                v=parent[v][i];
            }
        }
        u=parent[u][0];
    }

    return u;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int i, x, y, m;
    cin>>n;
    arr.resize(n+1);
    fill_n(&parent[0][0], 100010*17, -1);
    fill_n(&depth[0], 100010, -1);
    depth[1]=0;
    for(i=1;i<=n-1;i++){
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    dfs(1);
    connection();
    cin>>m;
    while(m--){
        cin>>x>>y;
        cout<<LCA(x, y)<<"\n";
    }

    return 0;
}