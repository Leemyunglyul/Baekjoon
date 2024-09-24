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

vector<int> edge[1001000];
int arr[1001000];
long long tree[4010000][2];
long long lazy[4010000];
int ss[1010000], ee[1010000];
int cnt=0;

void dfs(int now){
    ss[now]=++cnt;
    for(int i=0;i<edge[now].size();i++){
        dfs(edge[now][i]);
    }
    ee[now]=cnt;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node][0] = arr[start];
        tree[node][1] = arr[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][0] = min(tree[node*2][0] , tree[node*2+1][0]);
        tree[node][1] = max(tree[node*2][1] , tree[node*2+1][1]);
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node][0] += lazy[node];
        tree[node][1] += lazy[node];
        if(start!=end) {
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
        lazy[node]+=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node][0] = min(tree[node*2][0] , tree[node*2+1][0]);
    tree[node][1] = max(tree[node*2][1] , tree[node*2+1][1]);
}

long long query(int node, int start, int end, int left, int right, int lr) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        if(lr==0) return 9876543212;
        else return 0;
    }
    if (left <= start && end <= right) {
        if(lr==0) return tree[node][0];
        else return tree[node][1];
    }
    long long lsum = query(node*2, start, (start+end)/2, left, right, lr);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right, lr);
    if(lr==0) return min(lsum,rsum);
    else return max(lsum, rsum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, m, i, j, x, a, b, c, testn;
    char y;
    cin>>testn;
    while(testn--){
        cin>>n;
        cnt=0;
        fill_n(&lazy[0], 4010000, 0);
        fill_n(&ss[0], 1010000, 0);
        fill_n(&ee[0], 1010000, 0);
        for(i=1;i<=n;i++){
            edge[i].clear();
        } 
        for(i=1;i<=4*n;i++){
            tree[i][0]=987654321;
            tree[i][1]=0;
        }
        for(i=2;i<=n;i++){
            cin>>x;
            edge[x].push_back(i);
        }
        dfs(1);
        for(i=1;i<=n;i++)cin>>arr[ss[i]];
        init(1, 1,n);
        cin>>m;
        while(m--){
            cin>>y;
            if(y=='Q'){
                cin>>x;
                a=query(1, 1, n, ss[x], ee[x], 0);
                b=query(1, 1, n, ss[x], ee[x], 1);
                cout<<b-a<<"\n";
            }
            else{
                cin>>b>>c;
                update_range(1, 1, n, ss[b], ee[b], c);
            }
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