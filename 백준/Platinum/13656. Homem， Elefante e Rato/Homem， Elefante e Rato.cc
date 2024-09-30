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

int tree[400100][3];
int lazy[400100];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node][0] = 1;
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    }
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        int arr[3];
        //cout<<start<<"~~"<<end<<"=="<<tree[node][0]<<" "<<tree[node][1]<<" "<<tree[node][2]<<"\n";
        for(int i=0;i<=2;i++) arr[i]=tree[node][i];
        for(int i=0;i<=2;i++) tree[node][(i+lazy[node])%3]=arr[i];
        //cout<<start<<"~~"<<end<<"=="<<tree[node][0]<<" "<<tree[node][1]<<" "<<tree[node][2]<<"\n";
        if (start != end) {
            lazy[node*2] =(lazy[node*2]+ lazy[node])%3;
            lazy[node*2+1] =(lazy[node*2+1]+ lazy[node])%3;
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node]=(lazy[node]+1)%3;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right);
    update_range(node*2+1, (start+end)/2+1, end, left, right);
    for(int i=0;i<=2;i++) tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
}
tuple<int, int, int> query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return {0,0,0};
    }
    if (left <= start && end <= right) {
        return {tree[node][0], tree[node][1], tree[node][2]};
    }
    tuple<int, int, int> lsum = query(node*2, start, (start+end)/2, left, right);
    tuple<int, int, int> rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return {get<0>(lsum)+get<0>(rsum),get<1>(lsum)+get<1>(rsum),get<2>(lsum)+get<2>(rsum)};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, i, j, a, b, c;
    char x;
    while(1){
        cin>>n>>m;
        if(cin.eof() ||(n==0 & m==0)) break;
        fill_n(&tree[0][0], 400001*3, 0);
        fill_n(&lazy[0], 400001, 0);
        init(1, 1, n);
        for(i=1;i<=m;i++){
            cin>>x>>a>>b;
            if(x=='M') update_range(1, 1, n, a, b);
            else{
                tuple<int, int, int> y=query(1, 1, n, a, b);
                cout<<get<0>(y)<<" "<<get<1>(y)<<" "<<get<2>(y)<<"\n";
            }
        }
        cout<<"\n";
    }
    
}
