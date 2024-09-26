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

int tree[18400000][2];
int lazy[18400000];

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node][0] +=lazy[node];
        tree[node][1] +=lazy[node];
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
        lazy[node] +=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node][0] = min(tree[node*2][0],tree[node*2+1][0]);
    tree[node][1] = max(tree[node*2][1],tree[node*2+1][1]);
}
int query(int node, int start, int end, int left, int right, int x) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        if(x==0) return 99999;
        else return -99999;
    }
    if (left <= start && end <= right) {
       // cout<<start<<"~~"<<end<<"=="<<tree[node][x]<<endl;
        return tree[node][x];
    }
    int lsum = query(node*2, start, (start+end)/2, left, right, x);
    int rsum = query(node*2+1, (start+end)/2+1, end, left, right, x);
    if(x==0) return min(lsum, rsum);
    else return max(lsum, rsum);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int c, n, q, i, j, a, b, x,y, z;
    string s;
    cin>>n>>c>>q;
    while(q--){
        cin>>s;
        if(s=="state"){
            cin>>x;
            x++;
            cout<<query(1, 1, n, x, x, 0)<<"\n";
        }
        else if(s=="change"){
            cin>>x>>y;
            x++;
            if(y>=0){
                a=query(1, 1, n, x, x, 1);
                if(a+y>c) y=c-a;
            }
            else{
                a=query(1, 1, n, x, x, 0);
                if(a+y<0) y=-a;
            }
            update_range(1, 1, n, x, x, y);
            cout<<y<<"\n";
        }
        else{
            cin>>x>>z>>y;
            x++;z++;
            if(y>=0){
                a=query(1, 1, n, x, z, 1);
                if(a+y>=c) y=c-a;
            }
            else{
                a=query(1, 1, n, x, z, 0);
                if(a+y<=0) y=-a;
            }
            update_range(1, 1, n, x, z, y);
            cout<<y<<"\n";
        }
    }
}