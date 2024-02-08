#include<iostream>
#include<math.h>
#include<string>
#include<vector>

using namespace std;

int arr[20][20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x, y;
	cin >> x >> y;
	int i, j, k;
	for (i = 0,j=0 ; i < 8; i++) {
		arr[0][j++] = x[i] - 48;
		arr[0][j++] = y[i] - 48;
	}
	for (i = 15; i >=2; i--) {
		k = 16 - i;
		for (j = 0; j < i; j++) {
			arr[k][j] = (arr[k - 1][j] + arr[k - 1][j + 1])%10;
		}
	}
	cout << arr[14][0] << arr[14][1];
}