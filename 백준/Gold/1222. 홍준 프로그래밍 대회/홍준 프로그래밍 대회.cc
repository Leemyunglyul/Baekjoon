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

int arr[2001000];
int list[2001000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, x, j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        list[x]++;
    }
    for(i=1;i<=2000000;i++){
        for(j=i;j<=2000000;j+=i){
            arr[i]+=list[j];
        }
    }
    long long sum=0;
    for(i=1;i<=2000000;i++){
        if(arr[i]<=1) continue;
        sum=max(sum, (long long)i*arr[i]);
    }
    cout<<sum;

}


/*
for(i=1;i<=n;i++){
        
}
*/


/*
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

}*/