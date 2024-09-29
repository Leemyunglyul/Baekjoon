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

int arr[250100];
int tree[1010000][10];
int lazy[1010000];

void init(int node, int start, int end) {
    if (start == end) {
        for(int i=0;i<=9;i++){
            if(arr[start]==i)tree[node][i]++;
        }
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        for(int i=0;i<=9;i++){
            tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
        }
    }
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        int tmp[10];
        for(int i=0;i<=9;i++) tmp[i]=tree[node][i];
        for(int i=0;i<=9;i++){
            int x=(i+lazy[node])%10;
            tree[node][x] = tmp[i];
        }
        if(start!=end) {
            lazy[node*2] =(lazy[node*2]+ lazy[node])%10;
            lazy[node*2+1] =(lazy[node*2+1]+ lazy[node])%10;
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        update_lazy(node, start, end);
        return;

    }
    if (left <= start && end <= right) {
        lazy[node]=(lazy[node]+1)%10;
        update_lazy(node, start, end);
        return;
    }
    update_lazy(node, start, end);
    update_range(node*2, start, (start+end)/2, left, right);
    update_range(node*2+1, (start+end)/2+1, end, left, right);
    for(int i=0;i<=9;i++){
        tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
    }
}

int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        int sum=0;
        for(int i=1;i<=9;i++) sum+=tree[node][i]*i;
        return sum;
    }
    int lsum = query(node*2, start, (start+end)/2, left, right);
    int rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, m, x,r, a, b, c;
    cin>>n>>m;
    string s;
    cin>>s;
    for(i=1;i<=n;i++) arr[i]=s[i-1]-48;
    init(1, 1,n );
    while(m--){
        cin>>a>>b;
        cout<<query(1, 1, n, a, b)<<"\n";
        update_range(1, 1, n, a, b);
    }
    
}