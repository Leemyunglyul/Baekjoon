#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>

using namespace std;

int arr[100010][2];
int dp[100010][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testn;
    cin >> testn;
    while (testn--) {
        int n, i,j, x, y;
        cin >> n;
        for(j = 0; j <= 1; j++) {
            for(i = 1; i <= n; i++) {
                cin >> arr[i][j];
            }
        }
        dp[0][0] = dp[0][1] = 0;
        dp[1][0] = arr[1][0];
        dp[1][1] = arr[1][1];
        for (i = 2; i <= n; i++) {
            dp[i][0] = max(max(dp[i-2][0]+arr[i][0], dp[i-2][1]+arr[i][0]), max(dp[i-1][1] + arr[i][0], dp[i-1][0]));
            dp[i][1] = max(max(dp[i-2][1]+arr[i][1], dp[i-2][0]+arr[i][1]), max(dp[i-1][0] + arr[i][1], dp[i-1][1]));
        }
        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
    
    return 0;
}