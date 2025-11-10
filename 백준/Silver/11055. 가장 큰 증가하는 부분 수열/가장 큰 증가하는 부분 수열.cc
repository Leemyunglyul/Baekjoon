#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1010];
int dp[1010];
int sum[1010];
int anw = 0;

void solve(){
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        sum[i] = arr[i];
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                sum[i] = max(sum[i], sum[j] + arr[i]);
                anw = max(anw, sum[i]);
            }
        }
        anw = max(anw, sum[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >>n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    solve();
    cout << anw << "\n";

    return 0;
}