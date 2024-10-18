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

int arr[5100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, i, j, s, e, sum, idx;
    bool anw=false;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==k) anw=true;
    }
    if(anw){
        cout<<"1";
        return 0;
    }
    sort(arr+1, arr+n+1);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(arr[i]+arr[j]==k){
                cout<<"1";
                return 0;
            }
            if(arr[i]+arr[j]>k || j==n) continue;
            idx=lower_bound(arr+j+1, arr+n+1, k-arr[i]-arr[j])-arr;
            if(arr[idx]+arr[i]+arr[j]==k){
                cout<<"1";
                return 0;
            }
        }
    }
    cout<<"0";
}