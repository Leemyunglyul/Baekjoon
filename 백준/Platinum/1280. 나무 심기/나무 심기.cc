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

pair<long long, long long> segt[810000];

void update(int n, int st, int end, int t, long long diff){

    if(t<st || t>end) return; 
    segt[n]={segt[n].first+1, segt[n].second+diff};
   // cout<<n<<"~~"<<segt[n]<<endl;

    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t, diff);
    update(n*2+1, mid+1, end, t, diff);
}

pair<long long, long long> sum(int l, int r, int n, int st, int end){
    if(l<=st && end<=r) return segt[n];
    if(r<st || end<l) return {0, 0};

    int m =(st+end)/2;

    pair<long long, long long> a=sum(l, r, n*2, st, m);
    pair<long long, long long> b=sum(l, r, n*2+1, m+1, end);
    return {a.first+b.first, a.second+b.second};

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i, j, k, x, y, anw;
    long long big=1000000007;
    cin>>n;
    for(i=1,anw=0;i<=n;i++){
        cin>>x;
        if(i==1){
            update(1, 0, 200000, x, x);
            continue;
        }
        pair<long long, long long> a=sum(0, x, 1, 0, 200000);
        pair<long long, long long> b=sum(x+1, 200000, 1, 0, 200000);
        long long tmp=abs(a.second-a.first*x)%big+abs(b.second-b.first*x)%big;
        if(i==2) anw=tmp;
        else anw=(anw*tmp)%big;
        update(1, 0, 200000, x, x);
    }
    cout<<anw;

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