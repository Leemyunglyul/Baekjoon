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


int parent[110000];
vector<int> edge[110000];

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x]);
}

void unionn(int x, int y){
    x=find(x);
    y=find(y);
    parent[y]=x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j,k, x, y, anw, a, b;
    cin>>n>>k;
    for(i=1;i<=n;i++) parent[i]=i;
    for(i=1, anw=0;i<=k;i++){
        cin>>x>>y;
        if(anw>0) continue;
        if(find(x)==find(y)){
            anw=i;
            continue;
        }
        if(edge[x].size()>0 && edge[y].size()>0){
            unionn(edge[x][0], y);
            unionn(x,edge[y][0]);
        }
        else if(edge[x].size()>0) unionn(edge[x][0], y);
        else if(edge[y].size()>0) unionn(x,edge[y][0]);

        edge[x].push_back(y);
        edge[y].push_back(x);

    }
    cout<<anw;
}
