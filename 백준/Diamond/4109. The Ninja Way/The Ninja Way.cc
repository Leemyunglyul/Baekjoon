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
vector<pair<ll, ll>> list;
ll big=98765432192;

bool check(){
    ll i;
    for(i=0;i<edge.size();i++){
        ll from=get<0>(edge[i]);
        ll to=get<1>(edge[i]);
        ll len=get<2>(edge[i]);
        //if(arr[from]==big) continue;
        if(arr[to]>arr[from]+len){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, i, j, k, a, b, c, d, s, testn;
    //cin>>testn;
    while(1){
        cin>>n>>k;
        if(n==0) break;
        edge.clear();
        list.clear();
        for(i=1;i<=n;i++){
            cin>>arr[i];
            list.push_back({arr[i], i});
        }
        if(n==1){
            cout<<"0\n";
            continue;
        }
        
        sort(list.begin(), list.end()); 
        for(i=0;i<n-1;i++){
            a=list[i].second;
            b=list[i+1].second;
            if(a>b){
                edge.push_back({b, a, k});
            } 
            else{
                edge.push_back({a, b, k});
            } 
        }
        for(i=1;i<n;i++){
            edge.push_back({i+1, i, -1});
        }
        a=list[0].second;
        b=list[n-1].second;
        if(a>b) swap(a,b);
        fill_n(&arr[0], 1010, big);
        
        arr[a]=0;
        for(j=1;j<=n-1;j++){
            for(i=0;i<edge.size();i++){
                ll from=get<0>(edge[i]);
                ll to=get<1>(edge[i]);
                ll len=get<2>(edge[i]);
                if(arr[from]==big) continue;
                //cout<<from<<"~~~"<<to<<":: ";
                //cout<<arr[to]<<"vs"<<arr[from]+len<<endl;
                arr[to]=min(arr[to], arr[from]+len);
            }
        }
        if(!check()){
            cout<<"-1\n";
            continue;
        }
       //for(i=1;i<=n;i++)cout<<i<<"th : "<<arr[i]<<endl;
        cout<<abs(arr[b])<<"\n";
    }
    
}
