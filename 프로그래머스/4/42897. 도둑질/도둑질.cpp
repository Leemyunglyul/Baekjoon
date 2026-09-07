#include <string>
#include <vector>

using namespace std;

int arr[1000100];
int dp[1000100][2];
int dp_[1000100][2];

int solution(vector<int> money) {
    int answer = 0;
        
    int n = money.size();
    int i;
    
    for(i=0;i<n;i++) arr[i] = money[i];
    
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    dp[1][1] = arr[0];
    dp[1][0] = arr[0];

    
    for(i=2;i<n - 1;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + arr[i];
    }
    int a = max(dp[n-2][1], dp[n-2][0]);
    
    dp_[0][0] = 0;
    dp_[0][1] = 0;
    dp_[1][0] = 0;
    dp_[1][1] = arr[1];
    
    for(i=2;i<n - 1;i++){
        dp_[i][0] = max(dp_[i-1][0], dp_[i-1][1]);
        dp_[i][1] = dp_[i-1][0] + arr[i];
    }
    int b = max(dp_[n-2][1], dp_[n-2][0]+arr[n-1]);
    
    
    return max(a, b);
}