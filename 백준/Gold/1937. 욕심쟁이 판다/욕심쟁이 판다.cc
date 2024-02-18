#include<iostream>
#include<math.h>

using namespace std;

int arr[510][510];
int dp[510][510] = { 0 };
int n, big;

void dfs(int i, int j) {
	int x = 0;
	if (i > 1 && arr[i][j] < arr[i - 1][j]) {
		x++;
		if (dp[i - 1][j] == 0) dfs(i - 1, j);
		dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
	}
	if (j > 1 && arr[i][j] < arr[i][j - 1]) {
		x++;
		if(dp[i][j-1]==0) dfs(i, j - 1);
		dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
	}
	if (i < n && arr[i][j] < arr[i + 1][j]) {
		x++;
		if(dp[i+1][j]==0) dfs(i + 1, j);
		dp[i][j] = max(dp[i][j], dp[i+1][j] + 1);
	}
	if (j < n && arr[i][j] < arr[i][j+1]) {
		x++;
		if (dp[i][j+1] == 0) dfs(i , j+1);
		dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
	}
	if (x == 0) {
		dp[i][j] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j;
	cin >> n;
	big = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (dp[i][j]==0) dfs(i, j);
			big = max(big, dp[i][j]);
		}
	}
	cout << big;
}