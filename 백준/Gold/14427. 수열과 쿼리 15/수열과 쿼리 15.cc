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
//long long segt[400100];
/*
long long init(int node, int st, int end){

    if(st==end) return segt[node]=arr[st];
    int mid=(st+end)/2;

    return segt[node]=min(init(node*2, st, mid),init(node*2+1, mid+1, end));

}

long long update(int n, int st, int end, int t, long long diff){

    if(t<st || t>end) return segt[n];
    //segt[n]=min(diff, segt[n]);

    if(st==end){ 
        //cout<<n<<"=="<<arr[st]<<endl;
        return segt[n]=arr[st];
    }
    int mid=(st+end)/2;
    segt[n]=min(update(n*2, st, mid, t, diff),update(n*2+1, mid+1, end, t, diff));
    //cout<<st<<"~~~"<<end<<"=="<<segt[n]<<endl;
    return segt[n];
}

long long sum(int l, int r, int node, int st, int end){

    if(l<=st && end<=r) return segt[node];
    if(r<st || end<l) return 9876543211;

    int m =(st+end)/2;
    return min(sum(l, r, node*2, st, m),sum(l, r, node*2+1, m+1, end));

}*/

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //fill_n(&segt[0], 400100, 9876543211);
    //fill_n(&arr[0], 100100, 9876543211);
    long long n, i, j, k, x, y, a, b;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        pq.push({arr[i] ,i});
    }
    cin>>k;
    while(k--){
        cin>>x;
        if(x==1){
            cin>>a>>b;
            arr[a]=b;
            pq.push({b, a});
        }
        else{
            while(arr[pq.top().second]!=pq.top().first){
                pq.pop();
            }
            cout<<pq.top().second<<"\n";
        }
    }
    /*init(1, 1, n);
    for(i=1;i<=4*n;i++){
        //cout<<i<<"=="<<segt[i]<<endl;
    }
    cin>>k; 
    while(k--){
        cin>>x>>a>>b;
        
        if(x==2)cout<<sum(a, b, 1, 1, n)<<"\n";
        else{
            arr[a]=b;
            update(1, 1, n, a, b);
        }
    }*/

}

/*
for(i=1;i<=n;i++){
        
}
*/