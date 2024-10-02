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
#include <unordered_map>
typedef long long ll;

using namespace std;

ll anw=0;
ll arr[140000];
ll num[140000];
unordered_map<ll, ll> tmp;
unordered_map<ll, ll> tf;
ll n;

void track(ll m){
    if(m==0) return;
    ll i, sum1, sum2;
    for(i=1;i<=n;i++){
        num[i]+=((2*m)&arr[i]);
    }
    //sum1: 0, sum2: 1
    for(i=1, sum1=0, sum2=0;i<=n;i++){
        if(arr[i]&m){
           sum1+=tmp[num[i]];
        }
        else{
            sum2+=tf[num[i]]-tmp[num[i]];
            tmp[num[i]]++;
        }
        tf[num[i]]++;
    }
    if(sum1>=sum2) anw+=sum1;
    else anw+=sum2;
    tmp.clear();
    tf.clear();
    track(m/2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll i, j, m;
    cin>>m>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    track(m/2);
    cout<<anw;
}
