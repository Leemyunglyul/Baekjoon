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

int tree[410000][9];
int lazy[410000];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node][1] = 1;
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
    }
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        int arr[9];
        for(int i=0;i<=8;i++) arr[i]=tree[node][i];
        for(int i=0;i<=8;i++) tree[node][(i+lazy[node])%9]=arr[i];
        if (start != end) {
            lazy[node*2] =  (lazy[node*2] +lazy[node])%9;
            lazy[node*2+1] =  (lazy[node*2+1] +lazy[node])%9;
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right, int diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node]=(lazy[node]+diff)%9;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    for(int i=0;i<=8;i++)tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
}
int query(int node, int start, int end, int left, int right, int idx) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node][idx];
    }
    int lsum = query(node*2, start, (start+end)/2, left, right, idx);
    int rsum = query(node*2+1, (start+end)/2+1, end, left, right, idx);
    return lsum + rsum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q, i, j, x,y, a, b, c;
    cin>>n>>q;
    init(1, 1, n);
    while(q--){
        cin>>x>>y;
        x++;y++;
        for(i=0, a=0, b=0;i<9;i++){
            c=query(1, 1, n, x, y, i);
            if(c>=a){
                a=c;
                b=i;
            }
        }
        update_range(1, 1,n, x, y, b);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<9;j++){
            if(query(1, 1, n, i, i, j)>0){
                cout<<j<<"\n";
                break;
            }
        }
    }
}
