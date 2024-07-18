#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int arr[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, i, x, m;
	cin >> n;
	for (i = 1; i <= n; i++) cin >> arr[i];
	cin >> m;
	int sum = 0;
	while (m--) {
		cin >> x;
		sum += arr[x];
	}
	cout << sum;

}