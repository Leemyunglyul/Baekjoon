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

int arr[3][300100];
int tree[12000010];
int add[12000010]={0};
int lazy[12000010];

void init(int n, int st, int end){
    if(st==end){
        add[n]=1;
        return;
    }
    int mid=(st+end)/2;
    init(n*2, st, mid);
    init(n*2+1, mid+1, end);
    add[n]=add[n*2]+add[n*2+1];
}
void update(int n, int st, int end, int t){
    if(t<st || t>end) return;
    add[n]--;
    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t);
    update(n*2+1, mid+1, end, t);
    add[n]=add[n*2]+add[n*2+1];
}
int sum(int n, int st, int end, int x){
    if(st==end) return st;
    int m =(st+end)/2;
    if(add[n*2]>=x) return sum(n*2, st, m, x);
    else return sum(n*2+1, m+1, end, x-add[n*2]);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if(start==end) tree[node] +=lazy[node];
        else {
            lazy[node*2] +=lazy[node];
            lazy[node*2+1] +=lazy[node];
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
    return lsum + rsum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, s, e,m, x, a;
    cin>>n;
    for(i=0;i<3;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(j=1;j<=n;j++){
        if(arr[0][j]>=1)update_range(1, 1, 3000000, 1, arr[0][j], 1);
        if(arr[1][j]>=1)update_range(1, 1, 3000000, arr[0][j]+1, arr[0][j]+arr[1][j], 2);
        if(arr[2][j]>=1)update_range(1, 1, 3000000, arr[0][j]+arr[1][j]+1, arr[0][j]+arr[1][j]+arr[2][j], 5);
    }
    init(1, 1, 3000000);
    cin>>m;
    while(m--){
        cin>>x;
        a=sum(1, 1, 3000000, x);
        cout<<query(1, 1, 3000000, a, a)<<"\n";
        update(1, 1, 3000000, a);
    }
}
