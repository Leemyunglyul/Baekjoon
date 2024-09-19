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