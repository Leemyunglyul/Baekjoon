#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[101000];
long long tree[410000];
long long lazy[410000];
int ss[110000], ee[110000];
int cnt=-1;

void dfs(int now){
    ss[now]=++cnt;
    for(int i=0;i<edge[now].size();i++){
        dfs(edge[now][i]);
    }
    ee[now]=cnt;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node]=(lazy[node]==1)?end-start+1:0;
        if(start!=end) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
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
        tree[node]=(diff==1)?end-start+1:0;
        if(start!=end) {
            lazy[node*2] = diff;
            lazy[node*2+1] = diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node]=tree[node*2]+tree[node*2+1];
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

    long long n, m, i, j, x, a, b, c;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        edge[x].push_back(i);
    }
    dfs(0);
    init(1, 0, n);
    cin>>m;
    while(m--){
        cin>>a>>b;
        if(a<=2){
            if(ss[b]<ee[b]) update_range(1, 0, n, ss[b]+1, ee[b], a);
        }
        else{
            if(ss[b]<ee[b]) cout<<query(1, 0, n, ss[b]+1, ee[b])<<"\n";
            else cout<<"0\n";
        }
    }
}
