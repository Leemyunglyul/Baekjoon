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

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node].first != 0) {
        int mid=(start+end)/2;
        if(start==end) tree[node] += lazy[node].first+lazy[node].second;
        else {
            lazy[node*2] ={lazy[node*2].first+ lazy[node].first, lazy[node*2].second+ lazy[node].second};
            lazy[node*2+1] = {lazy[node*2+1].first+lazy[node].first, lazy[node*2+1].second+lazy[node].second+lazy[node].first*(mid-start+1)};
        }
        lazy[node] = {0,0};
    }
}

void update_range(int node, int start, int end, int left, int right, long long diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        int mid=(start+end)/2;
        if(start==end){
            lazy[node] = {lazy[node].first+1, lazy[node].second+start-left};
            return;
        }
        lazy[node*2] = {lazy[node*2].first+1, lazy[node*2].second+start-left};
        lazy[node*2+1] ={lazy[node*2+1].first+ 1, lazy[node*2+1].second+ mid-left+1};
        //cout<<start<<"~"<<mid<<"=="<<lazy[node*2].first<<" "<<lazy[node*2].second<<endl;
        //cout<<mid+1<<"~"<<end<<"=="<<lazy[node*2+1].first<<" "<<lazy[node*2+1].second<<endl;
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
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

    long long n, i, j, x, a, b, c, k;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];    
    }
    init(1, 1, n);
    cin>>k;
    while(k--){
        cin>>x;
        if(x==1){
            cin>>a>>b;
            update_range(1, 1, n, a, b, 0);
        }
        else{
            cin>>a;
            cout<<query(1, 1, n, a, a)<<"\n";
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