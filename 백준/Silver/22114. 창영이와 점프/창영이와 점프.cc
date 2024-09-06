#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int arr[100100];
int dp[100100][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, i, j;
    cin>>n>>k;
    int anw=0;
    for(i=2, dp[1][0]=1, dp[1][1]=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]<=k){
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1]+1;
        }
        else{
            dp[i][0]=1;
            dp[i][1]=dp[i-1][0]+1;
        }
        anw=max(anw, max(dp[i][0], dp[i][1]));
    }
    cout<<anw;
}

/*
for(i=1;i<=n;i++){
        
}
*/