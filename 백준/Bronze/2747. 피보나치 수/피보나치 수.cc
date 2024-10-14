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

int arr[47];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i;
    cin>>n;
    for(i=2, arr[1]=1;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];
}