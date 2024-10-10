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
#include <unordered_map>
typedef long long ll;

using namespace std;

vector<tuple<ll, ll, ll>> edge;
ll arr[43];
ll sum[43];
ll big=9876543211;

bool check(){
    ll i;
    for(i=0;i<edge.size();i++){
        ll from=get<0>(edge[i]);
        ll to=get<1>(edge[i]);
        ll len=get<2>(edge[i]);
        if(arr[from]==big) continue;
        if(arr[to]>arr[from]+len){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, i, j, k, a, b, c, d, s;
    cin>>n>>k;
    fill_n(&arr[0], 43, big);
    arr[0]=0;
    for(i=1;i<=n;i++){
        //edge.push_back({0, i, 0});
        edge.push_back({i-1, i, 1});
        edge.push_back({i, i-1, 0});
    } 
    while(k--){
        cin>>a>>b>>c;
        edge.push_back({a-1, b, c});
        edge.push_back({b, a-1, -c});
    }
    for(j=1;j<=n-1;j++){
        for(i=0;i<edge.size();i++){
            int from=get<0>(edge[i]);
            int to=get<1>(edge[i]);
            int len=get<2>(edge[i]);
            if(arr[from]==big) continue;
            arr[to]=min(arr[to], arr[from]+len);
        }
    }
    if(!check()){
        cout<<"NONE";
        return 0;
    }
    ll m1=0;
    for(i=1;i<=n;i++){
       // cout<<i<<"th "<<arr[i]<<endl;
        m1=max(m1, arr[i]-arr[i-1]);
    }
    if(m1>1) cout<<"NONE";
    else{
        for(i=1;i<=n;i++) sum[i]=arr[i]-arr[i-1];
        for(i=1;i<=n;i++){
            if(sum[i]==0) cout<<"-";
            else cout<<"#";
        }
    }
}
