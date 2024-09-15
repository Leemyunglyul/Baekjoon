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

long long arr[100100];
long long segt[400100];

long long init(int node, int st, int end){

    if(st==end) return segt[node]=arr[st];
    int mid=(st+end)/2;

    return segt[node]=init(node*2, st, mid)+init(node*2+1, mid+1, end);

}

void update(int n, int st, int end, int t, long long diff){

    if(t<st || t>end) return; 
    segt[n]+=diff;

    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t, diff);
    update(n*2+1, mid+1, end, t, diff);
}

long long sum(int l, int r, int node, int st, int end){

    if(l<=st && end<=r) return segt[node];
    if(r<st || end<l) return 0;

    int m =(st+end)/2;
    return sum(l, r, node*2, st, m)+sum(l, r, node*2+1, m+1, end);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i, j, k, x, y, a, b;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    init(1, 1, n);
    while(k--){
        cin>>x>>y>>a>>b;
        if(x>y) swap(x, y);
        cout<<sum(x, y, 1, 1, n)<<"\n";
        update(1, 1, n, a, b-arr[a]);
        arr[a]=b;
    }

}

/*
for(i=1;i<=n;i++){
        
}
*/