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
#include <unordered_map>
typedef long long ll;

using namespace std;

int tree[410000];
int lazy[410000];

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if(start==end) tree[node] += lazy[node];
        else {
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
    
    int n, i,k, x, y, sum, a, b;
    cin>>n;
    while(n--){
        cin>>x>>y;
        
        a=query(1, 1, 100000, x, x);
        b=query(1, 1, 100000, y, y);
        if(a>0) update_range(1, 1, 100000, x, x, -a);
        if(b>0) update_range(1, 1, 100000, y, y, -b);
        if(x+1==y);
        else update_range(1, 1, 100000, x+1, y-1, 1);
        cout<<a+b<<"\n";
    }
   
}
