#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int front[100100], back[100100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k, i, j, x;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> x;
		front[x]++;
	}
	for (i = 1; i <= n; i++) {
		cin >> x;
		back[x]++;
	}
	long long sum = 0;
	for (i = 1; i <= k; i++) {
		sum += (long long)front[i] * (n - back[i]) + (long long)back[i] * (n - front[i]);
	}
	cout << sum/2;
}