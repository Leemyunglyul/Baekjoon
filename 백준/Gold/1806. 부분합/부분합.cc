#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
vector<long long int> sum;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, s, i, x, start, end, len;
	cin >> n >> s;
	sum.push_back(0);
	for (i = 1; i <= n; i++) {
		cin >> x;
		sum.push_back(x + sum[i - 1]);
	}
	start = 0;
	end = 1;
	len = 100010;
	if (sum[n] < s) {
		cout << "0";
		return 0;
	}
	while (1) {
		while (sum[end] - sum[start] < s) {
			end++;
			if (end > n) {
				cout << len;
				return 0;
			}
		}
		len = min(len, end-start);
		while (sum[end] - sum[start] >= s && start<end) start++;
		len = min(len, end - start + 1);
	}
	cout << len;
}