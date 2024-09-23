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

vector<int> edge[201000];
long long tree[810000];
long long lazy[810000];
long long ss[210000], ee[210000], path[210000];
int cnt=0;

void dfs(int now, int x){
    path[now]=x;
    ss[now]=++cnt;
    for(int i=0;i<edge[now].size();i++){
        if(path[edge[now][i]]==0) dfs(edge[now][i], x+1);
    }
    ee[now]=cnt;
   // cout<<now<<"=="<<ss[now]<<"~~"<<ee[now]<<endl;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right, long long diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] += diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, m, i, j, x, a, b, c,r,y;
    cin>>n>>r;
    for(i=1;i<=n-1;i++){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(r, 1);
    cin>>m;
    while(m--){
        cin>>a>>b;
        if(a==1){
            update_range(1, 1, n, ss[b], ss[b], 1);
        }
        else{
            cout<<query(1, 1, n, ss[b], ee[b])*path[b]<<"\n";
        }
    }
}
