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

bool list[310][310];
int dp[310][310];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    fill_n(&list[0][0], 310*310, false);
    int n, m, i, j, x, y;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        list[x][y]=true;
    }
    for(i=0;i<=300;i++){
        for(j=0;j<=300;j++){
            if(i>0) dp[i][j]=dp[i-1][j];
            if(j>0) dp[i][j]=max(dp[i][j], dp[i][j-1]);
            if(list[i][j]){
                if(m<=i+j) continue;
                dp[i][j]+=m-i-j;
            }
        }   
    }   
    cout<<dp[300][300];
}