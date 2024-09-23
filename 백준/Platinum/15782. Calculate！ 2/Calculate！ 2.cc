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

vector<int> edge[101000];
long long arr[110000];
long long tree[410000];
long long lazy[410000];
long long ss[110000], ee[110000];
int cnt=0;

void dfs(int now){
    ss[now]=++cnt;
    for(int i=0;i<edge[now].size();i++){
        if(ss[edge[now][i]]==0) dfs(edge[now][i]);
    }
    ee[now]=cnt;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if((end-start+1)%2==1) tree[node] ^= lazy[node];
        if (start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
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
        lazy[node]^=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
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
    return lsum ^ rsum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, m, i, j, x, a, b, c,r,y;
    cin>>n>>m;
    for(i=1;i<=n-1;i++){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1);
    for(i=1;i<=n;i++){
        cin>>arr[ss[i]];
    }
    init(1, 1, n);
    while(m--){
        cin>>a;
        if(a==1){
            cin>>b;
            cout<<query(1, 1, n, ss[b], ee[b])<<"\n";
        }
        else{
            cin>>b>>c;
            update_range(1, 1, n, ss[b], ee[b], c);
        }
    }
}
