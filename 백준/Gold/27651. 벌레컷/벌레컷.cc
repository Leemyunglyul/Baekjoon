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

ll arr[1100000];
ll sum[1100000];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, i, j, s, e, anw, s1, s2;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    //init
    anw=0;s=1;e=2;
    for(e=2;e<=n-1;e++){
        s1=lower_bound(sum+1, sum+e, 2*sum[e]-sum[n])-sum-1;
        s2=lower_bound(sum+1, sum+e, sum[n]-sum[e])-sum-1;
        anw+=min(s1,s2);
    }
    cout<<anw;
    
}
