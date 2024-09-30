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

bool visited[110000]={false};
vector<int> edge[110000];
vector<int> tree[110000];

int init(int i, int node, int st, int end){
    if(st==end){
        return tree[i][node]=1;
    }
    int mid=(st+end)/2;
    return tree[i][node]=init(i, node*2, st, mid)+init(i, node*2+1, mid+1, end);
}

bool update(int i, int n, int st, int end, int t){
    if(t<st || t>end) return false;
    if(st==end){
        if(tree[i][n]>0){
            tree[i][n]--;
            return true;
        }
        return false;
    }
    int mid=(st+end)/2;
    if(update(i, n*2, st, mid, t)||update(i, n*2+1, mid+1, end, t)) {
        tree[i][n]--;
        return true;    
    }
    return false;
    
}

int sum(int i, int node, int st, int end, int x){
    if(st==end) return st;
    int m =(st+end)/2;
    if(tree[i][node*2]>=x) return sum(i, node*2, st, m, x);
    else return sum(i, node*2+1, m+1, end, x-tree[i][node*2]);
}

void dfs(int now){
    cout<<now<<" ";
    int x, y, i;
    while(1){
        for(i=0;i<edge[now].size();i++){
            x=edge[now][i];
            if(visited[x]){
                update(now, 1, 1, edge[now].size(), i+1);
            } 
        }
        if(tree[now][1]==0) return;
        if(tree[now][1]%2==0) x=sum(now, 1, 1, edge[now].size(), 1);
        else x=sum(now, 1, 1, edge[now].size(), tree[now][1]/2+1);
        update(now, 1, 1, edge[now].size(), x);
        x=edge[now][x-1];
        visited[x]=true;
        dfs(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int i, j, x, y,m, n;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        if(x==y) continue;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (i = 1; i <= n; i++) {
        if(edge[i].empty()) continue;
        sort(edge[i].begin(), edge[i].end());
        edge[i].erase(unique(edge[i].begin(), edge[i].end()), edge[i].end());
        tree[i].resize(edge[i].size()*4, 0);
        init(i, 1, 1, edge[i].size());
    }
    visited[1]=true;
    dfs(1);
}
