#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

long long dict[2001000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, x, i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x;
		dict[x]++;
	}
	cin >> k;
	long long sum = 0;
	for (i = 1; i <= k-1; i++) {
		if (dict[i] > 0 && dict[k - i] > 0 && k-i>0) {
			if (i == k - i) {
				sum += dict[i] * dict[k - i] / 2;
			}
			else {
				sum += dict[i] * dict[k - i];
			}
			dict[i] = 0;
			dict[k - i] = 0;
		}
	}
	cout << sum;
}