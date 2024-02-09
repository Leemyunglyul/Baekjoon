#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, sum;
	cin >> n;
	for (i = 0; i<n; i++) {
		cin >> j;
		arr.push_back(j);
	}
	sort(arr.begin(), arr.end());
	for (i = 0, sum=0; i < n; i++) {
		if (arr[0] != 1) {
			cout << "1";
			return 0;
		}
		if (i<n-1  && arr[i] + sum >= arr[i + 1] - 1) {
			sum = arr[i] + sum;
		}
		else {
			cout << arr[i] + sum + 1;
			return 0;
		}
	}
}