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

int arr[510000][2];
long long tree[2100000][2];

const long long big=1000000007;

void init(int n, int st, int end){
    if(st==end){
        tree[n][0]=arr[st][0];
        tree[n][1]=arr[st][1];
        return;
    }
    int mid=(st+end)/2;
    init(n*2, st, mid);
    init(n*2+1, mid+1, end);
    tree[n][0]=(tree[n*2][0]*tree[n*2+1][0])%big;
    tree[n][1]=(tree[n*2][1]*tree[n*2+1][0]+tree[n*2+1][1])%big;
}

void update(int n, int st, int end, int t, int x, long long d){
    if(t<st || t>end) return;
    
    if(st==end){
        tree[n][x]=d;
        if(x==0) tree[n][1]=0;
        else tree[n][0]=1;
        return;
    }
    int mid=(st+end)/2;
    update(n*2, st, mid, t, x, d);
    update(n*2+1, mid+1, end, t, x, d);
    tree[n][0]=(tree[n*2][0]*tree[n*2+1][0])%big;
    tree[n][1]=(tree[n*2][1]*tree[n*2+1][0]+tree[n*2+1][1])%big;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long i, j, x, y,m, n;
    cin>>n>>m;
    char c;
    for(i=1;i<=n;i++){
        cin>>c>>x;
        if(c=='+'){
            arr[i][1]=x;
            arr[i][0]=1;
        }
        else arr[i][0]=x;
    }
    init(1, 1, n);
    while(m--){
        cin>>x>>c>>y;
        if(c=='*'){
            update(1, 1, n, x, 0, y);
        }
        else{
            update(1, 1, n, x, 1, y);
        }
        cout<<tree[1][1]%big<<"\n";
    }
}
