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
ll arr[1010];
ll big=9876543212;

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
    
    ll n, i, j, k, m,a, b, c, d, s;
    cin>>n>>k>>m;
    fill_n(&arr[0], 1010, big);
    arr[1]=0;
    
    while(k--){
        cin>>a>>b>>c;
        edge.push_back({a, b, c});
        //edge.push_back({b, a, c});
    }
    while(m--){
        cin>>a>>b>>c;
        edge.push_back({b, a, -c});
        //edge.push_back({b, a, -c});
    }
    for(i=2;i<=n;i++){
        edge.push_back({i-1, i,big});
        edge.push_back({i, i-1, 0});
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
    if(!check()) cout<<-1;
    else if(arr[n]>=big) cout<<-2;
    else cout<<arr[n];
}
