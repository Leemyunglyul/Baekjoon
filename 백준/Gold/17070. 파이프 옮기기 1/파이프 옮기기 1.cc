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

bool arr[40][40];
long long dp[40][40][3]={0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j, x;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>x;
            arr[i][j]=(x==0)?false:true;
        }
    }
    for(i=1, dp[1][2][0]=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j] ||(i==1 && j==1) || (i==1 && j==2)) continue;
            if(i>1 && j>1){
                if(arr[i-1][j] || arr[i][j-1]);
                else{
                    dp[i][j][2]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
                }
            }
            if(j>1){
                dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][2];
            }
            if(i>1){
                dp[i][j][1]=dp[i-1][j][1]+dp[i-1][j][2];
            }
            //cout<<i<<"*"<<j<<"=="<<dp[i][j][1]+dp[i][j][0]+dp[i][j][2]<<endl;
        }
    }
    cout<<dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
}