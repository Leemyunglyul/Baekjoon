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

int arr[100100];
int tree[400100];
int check[100100];
stack<int> print;
long long init(int node, int st, int end){
    if(st==end) return tree[node]=1;
    int mid=(st+end)/2;
    return tree[node]=init(node*2, st, mid)+init(node*2+1, mid+1, end);
}
void update(int n, int st, int end, int t){
    if(t<st || t>end) return; 
    tree[n]--;
    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t);
    update(n*2+1, mid+1, end, t);
}
int query(int x, int node, int st, int end){
    if(st==end) return st;
    int m =(st+end)/2;
    if(x<=tree[node*2]) return query(x, node*2, st, m);
    else return query(x-tree[node*2], node*2+1, m+1, end);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, x;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1, arr+n+1);
    init(1, 1, n);
    for(i=1;i<=n;i++) cin>>check[i];
    for(i=n;i>=1;i--){
        x=query(check[i]+1, 1, 1, n);
        print.push(arr[x]);
        update(1, 1, n, x);
    }
    while(!print.empty()){
        cout<<print.top()<<"\n";
        print.pop();
    }
    
}