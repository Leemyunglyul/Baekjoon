#include<iostream>
#include<math.h>

using namespace std;

int arr[120];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, i, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	for (i = 1; i <= k; i++) {
		cin >> x;
		arr[x]--;
	}
	for (i = 1; i <= n; i++) {
		if (arr[i] >= 0) cout << "no\n";
		else cout << "yes\n";
	}
}