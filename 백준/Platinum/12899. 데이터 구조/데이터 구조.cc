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

//long long arr[2000100];
long long segt[8100000]={0};

/*long long init(int node, int st, int end){

    if(st==end) return segt[node]=arr[st];
    int mid=(st+end)/2;

    return segt[node]=init(node*2, st, mid)+init(node*2+1, mid+1, end);
}*/

void update(int n, int st, int end, int t, long long diff){

    if(t<st || t>end) return; 
    segt[n]+=diff;
   // cout<<n<<"~~"<<segt[n]<<endl;

    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t, diff);
    update(n*2+1, mid+1, end, t, diff);
}

long long sum(int l, int r, int n, int st, int end, int x){
    segt[n]--;
    /*if(l<=st && end<=r) return segt[node];
    if(r<st || end<l) return 0;*/
    if(st==end){
        return st;
    }
    int m =(st+end)/2;
    if(segt[n*2]>=x){ 
        return sum(l, r, n*2, st, m, x);
    }
    else{ 
        return sum(l, r, n*2+1, m+1, end, x-segt[n*2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i, j, k, x, y, a, b;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        if(x==1){
            update(1, 1, 2000000, y, 1);
        }
        else{
            cout<<sum(0, 0, 1, 1, 2000000, y)<<"\n";
            //update(1, 1, 2000000, y, -1);
        }
        //cout<<"///"<<segt[1]<<endl;
    }

}

/*
for(i=1;i<=n;i++){
        
}
*/