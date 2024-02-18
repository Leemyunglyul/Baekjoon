#include<iostream>
#include<math.h>

using namespace std;

pair<int,int> dp[100100];
int arr[100100][4];

int op(int x, int y, int pp) {
	if (pp == 1) return x + y;
	else if (pp == 2) return x - y;
	else if (pp == 3) return x * y;
	else return x / y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	dp[0] = {1, 1};
	int n, i, ddong;
	string x, y;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		if (x[0] == '+') arr[i][0] = 1;
		else if (x[0] == '-') arr[i][0] = 2;
		else if (x[0] == '*') arr[i][0] = 3;
		else if (x[0] == '/') arr[i][0] = 4;

		if (y[0] == '+') arr[i][2] = 1;
		else if (y[0] == '-') arr[i][2] = 2;
		else if (y[0] == '*') arr[i][2] = 3;
		else if (y[0] == '/') arr[i][2] = 4;

		arr[i][1] = x[1] - 48;
		arr[i][3] = y[1] - 48;
	}
	for (i = 1, ddong=0; i <= n; i++) {
		if (dp[i - 1].first > 0) dp[i].first = max(op(dp[i - 1].first, arr[i][1], arr[i][0]), op(dp[i - 1].first, arr[i][3], arr[i][2]));
		else dp[i].first = -1;
		if (i == 1) dp[i].second = 1;
		else dp[i].second = max(op(dp[i - 1].second, arr[i][3], arr[i][2]), op(dp[i - 1].second, arr[i][1], arr[i][0]));
		
		if (i > 1 && dp[i-2].first>0) {
			dp[i].second = max(dp[i].second, op(dp[i - 2].first, arr[i][1], arr[i][0]));
			dp[i].second = max(dp[i].second, op(dp[i - 2].first, arr[i][3], arr[i][2]));
		}
		//cout << dp[i].first << "//" << dp[i].second << endl;
		if (i>1 && dp[i-1].first <= 0 && dp[i].second <= 0) ddong = 1;
	}
	dp[n + 1].second = max(dp[n].second, dp[n - 1].first);
	if (dp[n].first <= 0 && dp[n + 1].second<=0) ddong = 1;
	if (ddong == 1) cout << "ddong game";
	else cout << max(dp[n].first, dp[n+1].second);
}