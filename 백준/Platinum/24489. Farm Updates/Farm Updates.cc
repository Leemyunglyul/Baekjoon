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

vector<tuple<int, int, bool>> edge;
int parent[100100];
vector<tuple<int, int, int>> query;
vector<int> adj[100100];
bool active[100100];
int anw[100100];

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

void unionn(int x, int y){
    active[find(x)]|=active[find(y)]|active[x]|active[y];
    x=find(x);
    y=find(y);
    if(x!=y){
        parent[y]=x;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    
}

void dfs(int x, int k){
    if(anw[x]>=k) return;
    anw[x]=k;
    for(int i=0;i<adj[x].size();i++){
        dfs(adj[x][i], k);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, i, j, x, y,z;
    char c;
    cin>>n>>m;
    fill_n(&active[0], 100100, true);
    edge.push_back({0, 0, true});
    for(i=1;i<=m;i++){
        cin>>c;
        if(c=='D'){
            cin>>x;
            active[x]=false;
            query.push_back({1, x, 0});
        }
        else if(c=='A'){
            cin>>x>>y;
            query.push_back({2, x, y});
            edge.push_back({x, y, true});
        }
        else{
            cin>>x;
            query.push_back({3, x, 0});
            edge[x]={get<0>(edge[x]), get<1>(edge[x]), false};
        }
    }
    for(i=1;i<=n;i++){
        parent[i]=i;
    } 
    for(i=1;i<edge.size();i++){
        if(!get<2>(edge[i])) continue;
        x=get<0>(edge[i]);
        y=get<1>(edge[i]);
        unionn(x,y);
    }
    for(i=1;i<=n;i++){
        if(active[find(i)]) anw[i]=m;
    }
    for(i=m-1;i>=0;i--){
        if(get<0>(query[i])==2) continue;
        if(get<0>(query[i])==1){
            x=get<1>(query[i]);
            if(!active[find(x)]){
                dfs(find(x), i);
                active[find(x)]=true;
            }
        }
        else{
            z=get<1>(query[i]);
            x=get<0>(edge[z]);
            y=get<1>(edge[z]);
            if(active[find(x)]&& !active[find(y)]){
                dfs(find(y), i);
            }
            else if(!active[find(x)]&& active[find(y)]){
                dfs(find(x), i);
            }
            unionn(x,y);
        }
    }
    for(i=1;i<=n;i++) cout<<anw[i]<<"\n";
}
