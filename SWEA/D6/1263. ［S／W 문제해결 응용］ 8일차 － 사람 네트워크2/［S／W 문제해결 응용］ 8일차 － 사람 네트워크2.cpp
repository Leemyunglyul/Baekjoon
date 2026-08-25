#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int arr[1010][1010];
int dp[1010][1010];
int n;

int solve(){

    fill_n(&arr[0][0], 1010 * 1010, 99999999);
    fill_n(&dp[0][0], 1010 * 1010, 99999999);
    int i, j, k;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==j) dp[i][j] = 99999999;
            else if(arr[i][j] != 0) dp[i][j] = arr[i][j];
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            for(k=1; k<=n; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int anw = 99999999;
    for(i=1; i<=n; i++){
        int tmp = 0;
        for(j=1; j<=n; j++){
            //cout<<dp[i][j]<<" ";
            if(i != j) tmp += dp[i][j];
        }
        //cout<<"\n";
        anw = min(anw, tmp);
    }
    return anw;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    { 
        cin>>n;
        cout << "#" << test_case << " " << solve() << "\n";

    }

    return 0;
}