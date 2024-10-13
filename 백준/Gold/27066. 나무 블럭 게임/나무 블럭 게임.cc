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
int sum[100100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, idx;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    } 
    sort(arr+1, arr+n+1);
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
    double anw=(double)sum[n]/n;
    for(i=1;i<n;i++){
        idx=(i+n)/2;
        anw=max(anw, (double)arr[idx]);
    }
    cout<<fixed;
    cout.precision(10);
    cout<<anw;
}