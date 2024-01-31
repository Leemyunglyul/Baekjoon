#include<iostream>
#include<math.h>

using namespace std;
int arr[3][6] = {0};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, x, y, z;
	cin >> n;
	for (i = 0; i < n; i++) {
		if (i == 0) {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			arr[0][3] = arr[0][0];
			arr[0][4] = arr[0][1];
			arr[0][5] = arr[0][2];
		}
		else {
			cin >> arr[1][0] >> arr[1][1] >> arr[1][2];
			arr[2][0] = min(arr[0][0], arr[0][1]) + arr[1][0];
			arr[2][1] = min(min(arr[0][0], arr[0][1]), arr[0][2]) + arr[1][1];
			arr[2][2] = min(arr[0][2], arr[0][1]) + arr[1][2];

			arr[2][3] = max(arr[0][3], arr[0][4]) + arr[1][0];
			arr[2][4] = max(max(arr[0][3], arr[0][4]), arr[0][5]) + arr[1][1];
			arr[2][5] = max(arr[0][4], arr[0][5]) + arr[1][2];

			for (j = 0; j < 6; j++) {
				arr[0][j] = arr[2][j];
			}
		}
	}
	cout << max(max(arr[0][3], arr[0][4]), arr[0][5]) << " " << min(min(arr[0][0], arr[0][1]), arr[0][2]);
}