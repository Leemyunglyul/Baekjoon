#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
int arr[100002][2] = {0};
int a[100002] = { 0 };

int main() {
	int n, m, x, y, j, i, sum;
	cin >> n;
	while (n--) {
		cin >> m;
		for (i = 1; i <= m; i++) {
			cin >> x >> y;
			arr[x][0] = y;
		}
		for (i = 2, arr[1][1]=arr[1][0]; i <= m; i++) {
			arr[i][1] = arr[i][0] < arr[i-1][1] ? arr[i][0] : arr[i - 1][1];
		}
		sum = m;
		for (i = m; i >=2; i--) {
			if (arr[i][0] > arr[i - 1][1]) sum--;
		}
		cout << sum<<endl;
	}
}