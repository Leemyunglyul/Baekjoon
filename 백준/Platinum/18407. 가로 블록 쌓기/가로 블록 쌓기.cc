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

vector<pair<int, int>> q;
map<int, int> tf;
vector<ll> arr;
ll tree[801000];
ll lazy[801000];

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = lazy[node];
        if (start != end) {
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
        lazy[node]=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = max(tree[node*2], tree[node*2+1]);
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
    return max(lsum, rsum);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, i, j, x,p, a,b, y,m;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        q.push_back({x, y});
        arr.push_back(y);
        arr.push_back(x+y);
    }
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1000000000);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    m=arr.size()-1;
    for(i=1;i<=m;i++){
        tf[arr[i]]=i;
    }
    for(i=0;i<n;i++){
        a=q[i].first;
        b=q[i].second;
        x=query(1, 1, m, tf[b]+1, tf[a+b]);
        update_range(1, 1, m, tf[b]+1, tf[a+b], x+1);
    }
    cout<<tree[1]<<"\n";
}
