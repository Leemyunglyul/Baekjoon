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

int arr[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, i, j, y, a, b, sum;
    cin>>n;
    for(i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1, arr+n+1);
    for(i=n, sum=0;i>=1;i--){
        b=n+1-i;
        if(arr[i]<b-1) continue;
        sum+=arr[i]-b+1;
    }
    cout<<sum;
}