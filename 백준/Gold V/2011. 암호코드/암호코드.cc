#include<iostream>
#include<math.h>
#include<string>

using namespace std;
int dp1[5010] = { 0 };
int dp2[5010] = { 0 };
long long int sum[5010] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x;
	cin >> x;
	int i, j, temp;
	for (i = 0; i < x.size(); i++) {
		if (x[i] - 48 > 0) dp1[i]++;
		//cout << dp1[i] << "//";
	}//cout << endl;
	for (i = 0; i < x.size() - 1; i++) {
		temp = (x[i] - 48) * 10 + x[i + 1] - 48;
		if (x[i]!=48 && temp >= 1 && temp <= 26) dp2[i]++;
		//cout << dp2[i] << "//";
	}//cout << endl;
	for (i = 2, sum[0] = dp1[0], sum[1] = sum[0] * dp1[1] + dp2[0]; i < x.size(); i++) {
		sum[i] = (sum[i - 1] * dp1[i] + sum[i - 2] * dp2[i - 1]) % 1000000;
		//cout << sum[i] << "//";
	}//cout << endl;
	cout << sum[x.size() - 1];
}