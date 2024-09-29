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
#include <climits>

using namespace std;

vector<long long> edge[101000];
long long aa[100100];
long long len[100100];
long long arr[100100];
long long tree[410000];
long long lazy[410000];
long long ss[110000], ee[110000];
long long small=-654321987654321;
long long cnt=0;

void dfs(long long now, long long x){
    ss[now]=++cnt;
    arr[now]=x+len[now];
    for(int i=0;i<edge[now].size();i++){
        dfs(edge[now][i], arr[now]);
    }
    ee[now]=cnt;
}
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = aa[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
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
        lazy[node] += diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = max(tree[node*2],tree[node*2+1]);
}

long long query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return small;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return max(lsum , rsum);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long n, i, j, m, x,r, a, b, c;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        if(x==0) r=i;
        else edge[x].push_back(i);
    }
    fill_n(&tree[0], 401000, small);
    for(i=1;i<=n;i++){
        cin>>len[i];
    }
    dfs(r, 0);
    for(i=1;i<=n;i++) aa[ss[i]]=arr[i];
    init(1, 1, n);
    cin>>m;
    while(m--){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            update_range(1, 1, n, ss[b], ee[b], c-len[b]);
            len[b]=c;
        }
        else{
            cin>>b;
            //cout<<query(1, 1, n, ss[b], ee[b])<<"vs"<<query(1, 1, n, ss[b], ss[b])<<"\n";
            cout<<query(1, 1, n, ss[b], ee[b])-query(1, 1, n, ss[b], ss[b])<<"\n";
        }
    }

}