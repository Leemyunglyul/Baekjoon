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

long long arr[110000];
long long tree[410000];
pair<long long, long long> lazy[410000];
long long mod=1000000007;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    } else {
        tree[node]=init(node*2, start, (start+end)/2)+init(node*2+1, (start+end)/2+1, end);
        return tree[node]%=mod;
    }
}
void update_lazy(int node, int start, int end) {
    int mid=(start+end)/2;
    pair<long long, long long> a={1,0};
    if (lazy[node]!=a) {
        tree[node] =(tree[node]*lazy[node].first+lazy[node].second*(end-start+1)) %mod;
        if(start!=end) {
            lazy[node*2].first=lazy[node*2].first*lazy[node].first%mod;
            lazy[node*2].second=(lazy[node*2].second*lazy[node].first+lazy[node].second)%mod;
            lazy[node*2+1].first=lazy[node*2+1].first*lazy[node].first%mod;
            lazy[node*2+1].second=(lazy[node*2+1].second*lazy[node].first+lazy[node].second)%mod;
        }
    }
    lazy[node] = {1,0};
}

void update_range(int node, int start, int end, int left, int right, long long x, long long diff) {
    update_lazy(node, start, end);
    int mid=(start+end)/2;
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node]={x, diff};
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right,x, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right,x, diff);
    tree[node] = (tree[node*2] + tree[node*2+1])%mod;
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
    return (lsum + rsum)%mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i, j, x, a, b, c, k, y;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];    
    }
    for(i=1;i<=4*n;i++){
        lazy[i]={1, 0};    
    }
    init(1, 1, n);
    cin>>k;
    while(k--){
        cin>>x;
        if(x<=3){
            cin>>a>>b>>c;
            if(x==1) y=1;
            else if(x==2){
                y=c;
                c=0;
            }
            else y=0;
            update_range(1, 1, n, a, b, y, c);
        }
        else{
            cin>>a>>b;
            cout<<query(1, 1, n, a, b)<<"\n";
        }
    }
}


/*
for(i=1;i<=n;i++){
        
}
*/


/*
    segment tree

long long init(int node, int st, int end){

    if(st==end) return segt[node]=arr[st];
    int mid=(st+end)/2;

    return segt[node]=init(node*2, st, mid)+init(node*2+1, mid+1, end);

}

void update(int n, int st, int end, int t, long long diff){

    if(t<st || t>end) return; 
    segt[n]+=diff;

    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t, diff);
    update(n*2+1, mid+1, end, t, diff);
}

long long sum(int l, int r, int node, int st, int end){

    if(l<=st && end<=r) return segt[node];
    if(r<st || end<l) return 0;

    int m =(st+end)/2;
    return sum(l, r, node*2, st, m)+sum(l, r, node*2+1, m+1, end);

}*/

/*
lazy segment tree

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
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
        tree[node] += (end-start+1)*diff;
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


*/

/*
euler technique

void dfs(int now){
    ss[now]=++cnt;
    for(int i=0;i<edge[now].size();i++){
        dfs(edge[now][i]);
    }
    ee[now]=cnt;
}

 */