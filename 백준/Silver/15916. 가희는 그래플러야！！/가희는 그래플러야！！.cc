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

ll arr[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, i, j, k;
    bool anw=false;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    cin>>k;
    for(i=1;i<=n;i++){
        ll x=k*(i-1);
        ll y=k*i;
        if((i>1 && x==arr[i-1]) || y==arr[i]) anw=true;
        if(x<arr[i-1] && y>arr[i]) anw=true;
        if(x>arr[i-1] && y<arr[i])anw=true;
    }
    if(anw) cout<<"T";
    else cout<<"F";
}