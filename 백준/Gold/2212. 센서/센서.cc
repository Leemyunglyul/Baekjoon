#include<iostream>
#include<math.h>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> input;
vector<int> diff;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, x, i, sum, j;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> x;
		input.push_back(x);
	}
	sort(input.begin(), input.end());
	for (i = 0; i < input.size() - 1; i++) {
		if (input[i + 1] != input[i]) diff.push_back(input[i + 1] - input[i]);
	}
	if (diff.empty() || k>=diff.size()+1) {
		cout << "0";
		return 0;
	}
	if (!diff.empty()) sort(diff.begin(), diff.end());
	for (i = 0, sum = 0; i < diff.size() - (k - 1); i++) {
		sum += diff[i];
	}
	cout << sum;
}