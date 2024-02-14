#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

long long int arr[52] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j;
	cin >> n;
	arr[2] = 3;
	for (i = 4; i <= n; i += 2) {
		arr[i] = arr[i - 2] * 3;
		for (j = 2; j <= i - 4; j += 2) {
			arr[i] += (arr[j] * 2);
		}
		arr[i] += 2;
		
	}
	cout << arr[n];
}