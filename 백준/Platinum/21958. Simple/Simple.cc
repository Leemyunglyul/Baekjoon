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

using namespace std;

long long arr[200100];
long long tree[810000][4];
long long lazy[810000];
long long big=98765432197654321;

void init(int node, int start, int end) {
    if (start == end) {
        if(arr[start]%2==0){
            tree[node][2]=arr[start];
            tree[node][3]=arr[start];
        }
        else{
            tree[node][0] = arr[start];
            tree[node][1]=arr[start];
        } 
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][0] = min(tree[node*2][0], tree[node*2+1][0]);
        tree[node][1] = max(tree[node*2][1], tree[node*2+1][1]);
        tree[node][2] = min(tree[node*2][2], tree[node*2+1][2]);
        tree[node][3] = max(tree[node*2][3], tree[node*2+1][3]);
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if(lazy[node]%2==0){
            if(tree[node][0]<big){
                tree[node][0]+=lazy[node];
                tree[node][1]+=lazy[node];
            } 
            if(tree[node][2]<big){
                tree[node][2]+=lazy[node];
                tree[node][3]+=lazy[node];
            } 
        }
        else{
            swap(tree[node][0], tree[node][2]);
            swap(tree[node][1], tree[node][3]);
            if(tree[node][0]>=big){
                tree[node][0]=big;
                tree[node][1]=0;
            } 
            else{
                tree[node][0]+=lazy[node];
                tree[node][1]+=lazy[node];
            }
            if(tree[node][2]>=big){
                tree[node][2]=big;
                tree[node][3]=0;
            }
            else{
                tree[node][2]+=lazy[node];
                tree[node][3]+=lazy[node];
            } 
        }
        if(start!=end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, long long diff) {
    if (left > end || right < start) {
        update_lazy(node, start, end);
        return;
    }
    if (left <= start && end <= right) {
        lazy[node]+=diff;
        update_lazy(node, start, end);
        return;
    }
    update_lazy(node, start, end);
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node][0] = min(tree[node*2][0], tree[node*2+1][0]);
    tree[node][1] = max(tree[node*2][1], tree[node*2+1][1]);
    tree[node][2] = min(tree[node*2][2], tree[node*2+1][2]);
    tree[node][3] = max(tree[node*2][3], tree[node*2+1][3]);
}

pair<long long, long long>query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return {0, big};
    }
    if (left <= start && end <= right) {
        return {tree[node][1], tree[node][2]};
    }
    pair<long long, long long> lsum = query(node*2, start, (start+end)/2, left, right);
    pair<long long, long long> rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return {max(lsum.first, rsum.first), min(lsum.second, rsum.second)};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, i, j, m, x,r, a, b, c;
    cin>>n;
    for(i=1;i<=4*n;i++){
        tree[i][0]=big;
        tree[i][2]=big;
    }
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>m;
    init(1, 1, n);
    while(m--){
        cin>>x;
        if(x==0){
            cin>>a>>b>>c;
            update_range(1, 1, n, a, b, c);
        }
        else{
            cin>>a>>b;
            pair<long long, long long> p=query(1, 1, n, a, b);
            if(p.second>=big) cout<<"-1 ";
            else cout<<p.second<<" ";
            if(p.first<=0) cout<<"-1\n";
            else cout<<p.first<<"\n";
           
        }
    }
}