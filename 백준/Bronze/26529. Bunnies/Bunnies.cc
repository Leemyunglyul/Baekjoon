#include<iostream>
#include<math.h>

using namespace std;

long long int dp[50];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	dp[0] = 1;
	dp[1] = 1;
	int i, testn, n;
	for (i = 2; i <= 45; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cin >> testn;
	while (testn--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}