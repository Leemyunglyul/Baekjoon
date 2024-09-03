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

int arr[300000];
int dp[300000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i, j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    long long sum=0;
    for(i=2;i<=n;i++){
        dp[i]=max((int)ceil(log2((double)arr[i-1]/(double)arr[i])+(double)dp[i-1]),0);
            sum+=dp[i];
    }
    cout<<sum;
}

/*
for(i=1;i<=n;i++){
        
}
*/