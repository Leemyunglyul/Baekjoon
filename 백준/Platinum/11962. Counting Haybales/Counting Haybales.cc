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
#include <unordered_map>
typedef long long ll;

using namespace std;

ll tree[801000][2];
ll lazy[801000];
ll arr[201000];
ll big=987654345654;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node][0] = arr[start];
        tree[node][1] = arr[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
        tree[node][0] = min(tree[node*2][0],tree[node*2+1][0]);
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node][1] += (end-start+1)*lazy[node];
        tree[node][0] += lazy[node];
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
        lazy[node]+=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
    tree[node][0] = min(tree[node*2][0],tree[node*2+1][0]);
}
long long query(int node, int start, int end, int left, int right, int t) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        if(t==0) return big;
        else return 0;
    }
    if (left <= start && end <= right) {
        return tree[node][t];
    }
    long long lsum = query(node*2, start, (start+end)/2, left, right, t);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right, t);
    if(t==0) return min(lsum, rsum);
    else return lsum+rsum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    ll n, i, j, a, b, c, d, k;
    char x;
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>arr[i];
    init(1, 1, n);
    while(k--){
        cin>>x;
        if(x=='M'){
            cin>>a>>b;
            cout<<query(1, 1, n, a, b, 0)<<"\n";
        }
        else if(x=='P'){
            cin>>a>>b>>c;
            update_range(1, 1, n, a, b, c);
        }
        else{
            cin>>a>>b;
            cout<<query(1, 1, n, a, b, 1)<<"\n";
        }
    }
    
}
