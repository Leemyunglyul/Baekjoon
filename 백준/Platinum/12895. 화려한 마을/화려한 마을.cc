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

long long tree[410000];
long long lazy[410000];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] | tree[node*2+1];
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = lazy[node];
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
        tree[node] = diff;
        if(start!=end){
            lazy[node*2] = diff;
            lazy[node*2+1] = diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node]=tree[node*2]|tree[node*2+1];
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
    return lsum | rsum;
}

int check(int x, int t){
    int s, sum, i;
    
    for(i=0,sum=0,s=1;i<t;i++){
        if(x&s) sum++;
        s=s<<1;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, m, i, j,a, b, c, t;
    char x;
    cin>>n>>t>>m;
    init(1, 1, n);
    while(m--){
        cin>>x;
        if(x=='C'){
            cin>>a>>b>>c;
            if(a>b) swap(a,b);
            update_range(1, 1, n, a, b, 1<<(c-1));
        }
        else{
            cin>>a>>b;
            if(a>b) swap(a,b);
            cout<<check(query(1, 1, n, a,b),t)<<"\n";
        }
    }
}
