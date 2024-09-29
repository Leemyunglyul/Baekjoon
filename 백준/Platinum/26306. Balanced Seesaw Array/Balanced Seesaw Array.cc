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

long long arr[100100];
long long tree[410000][2];
long long lazy[410000][2];

void init(int node, long long start, long long end) {
    if (start == end) {
        tree[node][0] = arr[start];
        tree[node][1] = arr[start]*start;
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
        tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
    }
}

void update_lazy(int node, long long start, long long end) {
    if (lazy[node][0] != 1 || lazy[node][1]!=0) {
        tree[node][0] = lazy[node][0]*tree[node][0]+lazy[node][1]*(end-start+1);
        long long tmp=(end+start)*(end-start+1);
        tree[node][1]=lazy[node][0]*tree[node][1]+lazy[node][1]*tmp/2;
        if (start != end) {
            lazy[node*2][0]*=lazy[node][0];
            lazy[node*2+1][0]*=lazy[node][0];
            lazy[node*2][1]= lazy[node*2][1]*lazy[node][0]+lazy[node][1];
            lazy[node*2+1][1]= lazy[node*2+1][1]*lazy[node][0]+lazy[node][1];
        }
        lazy[node][0] = 1;
        lazy[node][1] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right,long long x, long long diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node][0]=x;
        lazy[node][1]=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right,x,  diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, x, diff);
    tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
}
pair<long long ,long long> query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return {0, 0};
    }
    if (left <= start && end <= right) {
        return {tree[node][0], tree[node][1]};
    }
    pair<long long ,long long> lsum = query(node*2, start, (start+end)/2, left, right);
    pair<long long ,long long> rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return {lsum.first+rsum.first, lsum.second+rsum.second};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, i, j, m, x,r, a, b, c;
    cin>>n>>m;
    for(i=1;i<=4*n;i++) lazy[i][0]=1;
    for(i=1;i<=n;i++) cin>>arr[i];
    init(1, 1,n );
    while(m--){
        cin>>a;
        if(a==1){
            cin>>b>>c>>x;
            update_range(1, 1, n, b, c, 1, x);
        }
        else if(a==2){
            cin>>b>>c>>x;
            update_range(1, 1, n, b, c, 0, x);
        }
        else{
            cin>>a>>b;
            pair<long long, long long> p=query(1, 1, n, a, b);
            long long x1=p.first;
            long long x2=p.second-p.first*(a-1);
            if(x2==0 && x1==0){
                cout<<"Yes\n";
                continue;
            }
            else if(x1==0 || x2==0){
                cout<<"No\n";
                continue;
            }
            long long x3=x2/x1;
            if(x2%x1==0 && 1<=x3 && x3<=(b-a+1)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    
}