#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101][101][101];
string a, b, c;

void solve(){

    a=' '+a;
    b=' '+b;
    c=' '+c;

    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            for(int k=1;k<c.size();k++){
                if(a[i]==b[j]&&b[j]==c[k]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k]=max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    cout<<dp[a.size()-1][b.size()-1][c.size()-1];
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    cin>>a>>b>>c;
    solve();

    return 0;
}