#include<iostream>
#include<math.h>

using namespace std;

int arr[110];
long long int anw[110][21] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, i, j, sum;
	cin >> n;
	for (i = 1; i <= n; i++) cin >> arr[i];
	for (i = 1; i < n; i++) {
		if (i == 1) {
			anw[i][arr[i]] = 1;
			continue;
		}
		for (j = 0; j <= 20; j++) {
			if (anw[i - 1][j] > 0) {
				if (j + arr[i] <= 20) anw[i][j + arr[i]] += anw[i - 1][j];
				if (j - arr[i] >= 0) anw[i][j - arr[i]] += anw[i - 1][j];
			}
		}
	}
	cout << anw[n - 1][arr[n]];
}