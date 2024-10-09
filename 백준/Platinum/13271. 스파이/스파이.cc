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

vector<tuple<int, int, int>> edge;
ll arr[1010];
ll big=987654321212;

bool check(){
    ll i;
    for(i=0;i<edge.size();i++){
        int from=get<0>(edge[i]);
        int to=get<1>(edge[i]);
        int len=get<2>(edge[i]);
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
    bool ch=false;
    cin>>n>>k;
    while(k--){
        cin>>d>>a>>b>>c;
        if(d==1){
            edge.push_back({a, b, -c});
            s=a;
        } 
        else if(d==2){
            edge.push_back({b, a, c});
            s=b;
        } 
        else{
            edge.push_back({a, b, -c});
            edge.push_back({b, a, c});
            s=a;
        }
    }
    //fill_n(&arr[0], 1010, big);
    arr[s]=0;
    //for(i=2;i<=n;i++) edge.push_back({1, i, 0});
    for(j=1;j<=n;j++){
        for(i=0;i<edge.size();i++){
             int from=get<0>(edge[i]);
            int to=get<1>(edge[i]);
            int len=get<2>(edge[i]);
            if(arr[from]==big) continue;
            arr[to]=min(arr[to], arr[from]+len);
        }
    }
    if(!check()){
        cout<<"-1";
        return 0;
    }
    ll m1=big;
    ll m2=0;
    for(i=1;i<=n;i++){
        if(arr[i]==big) continue;
        m1=min(m1, arr[i]);
        m2=max(m2, arr[i]);
    }
    if(m2-m1>100) cout<<"-1";
    else cout<<m2-m1;

    return 0;
}
