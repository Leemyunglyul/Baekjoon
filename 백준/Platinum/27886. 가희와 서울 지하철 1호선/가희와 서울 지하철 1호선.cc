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

int tree[810000];
int lazy[810000];
vector<tuple<int, int, int>> check;
int print[210000];
int tre[810000];

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if(start==end){
            tree[node] = __gcd(tree[node], lazy[node]);
        }
        else {
            lazy[node*2]=__gcd(lazy[node*2], lazy[node]);
            lazy[node*2+1]=__gcd(lazy[node*2+1], lazy[node]);
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
        lazy[node]=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
}

int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int lsum = query(node*2, start, (start+end)/2, left, right);
    int rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return __gcd(lsum,rsum);
}

int ini(int node, int st, int end){

    if(st==end) return tre[node]=print[st];
    int mid=(st+end)/2;

    return tre[node]=max(ini(node*2, st, mid),ini(node*2+1, mid+1, end));
}

int sum(int l, int r, int node, int st, int end){

    if(l<=st && end<=r) return tre[node];
    if(r<st || end<l) return 0;

    int m =(st+end)/2;
    return max(sum(l, r, node*2, st, m),sum(l, r, node*2+1, m+1, end));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q, i, j, a, b, c;
    cin>>n>>q;
    while(q--){
        cin>>a>>b>>c;
        update_range(1, 1, n, a, b, c);
        check.push_back({a,b,c});
    }
    for(i=1;i<=n;i++){
        print[i]=query(1, 1, n, i, i);
        if(print[i]==0) print[i]=1;
    }
    ini(1, 1, n);
    for(i=0;i<check.size();i++){
       a=get<0>(check[i]);
       b=get<1>(check[i]);
       c=get<2>(check[i]);
       if(sum(a, b, 1, 1, n)!=c){
            cout<<"-1";
            return 0;
       }
    }
    for(i=1;i<=n;i++){
        if(print[i]>0)cout<<print[i]<<" ";
        else cout<<"1 ";
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

void dfs(int now){
    ss[now]=++cnt;
    for(int i=0;i<edge[now].size();i++){
        dfs(edge[now][i]);
    }
    ee[now]=cnt;
}

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