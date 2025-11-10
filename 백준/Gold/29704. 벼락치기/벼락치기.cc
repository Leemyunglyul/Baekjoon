#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct q{
    int n;
    int m;
};

int n, d;
q arr[1010];
int dp[1010][1010];
int fine = 0;

void solve(){
    sort(arr + 1, arr + n + 1, [](q a, q b){
        if(a.n == b.n) return a.m > b.m;
        return a.n < b.n;
    });


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= d; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= arr[i].n)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].n] + arr[i].m);
                
        }
    }

    cout << fine - dp[n][d] << "\n";
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >>n>>d;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].n >> arr[i].m;
        fine += arr[i].m;
    }
    solve();

    return 0;
}