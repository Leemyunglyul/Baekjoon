#include<iostream>
#include<math.h>

using namespace std;

int arr[100100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i;
	cin >> n;
	arr[1] = -1;
	arr[2] = 1;
	arr[3] = -1;
	arr[4] = 2;
	arr[5] = 1;
	for (i = 6; i <= n; i++) {
		if (arr[i - 5] == -1 && arr[i - 2] == -1) arr[i] = -1;
		else if (arr[i - 5] == -1) arr[i] = arr[i - 2] + 1;
		else if (arr[i - 2] == -1) arr[i] = arr[i - 5] + 1;
		else arr[i] = min(arr[i - 2], arr[i - 5]) + 1;
	}
	cout << arr[n];
}