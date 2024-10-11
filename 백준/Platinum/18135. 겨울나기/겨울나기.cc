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

ll tree[8001000];
ll lazy[8001000];
map<int, int> f;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    ll n, i, j, a, b, c, d, k;
    cin>>n>>k;
    for(i=1;i<=k;i++){
        cin>>a>>b>>c;
        for(j=a;j<=b;j++) f[j]=i;
        update_range(1, 1, k, f[a], f[b], c);
    }
    while(1){
        cin>>a>>b>>c;
        if(a+b+c==0) break;
        b=f[b];
        c=f[c];
        if(a==1){
            if(b>c){
                
                cout<<query(1, 1, k, b, k)+query(1, 1, k, 1, c)<<"\n";
            }
            else cout<<query(1, 1, k, b, c)<<"\n";
            
        }
        else{
            cin>>d;
            if(b>c){
                update_range(1, 1, k, b, k, d);
                update_range(1, 1, k, 1, c, d);
            }
            else update_range(1, 1, k, b, c, d);
        }
    }
    
}
