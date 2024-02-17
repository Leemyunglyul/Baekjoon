#include<iostream>
#include<math.h>

using namespace std;

int arr[4] = {0, 1, 0, 0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, n, x, y;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		if (x == y || arr[x] + arr[y] == 0) continue;
		if (arr[x] == 1) {
			arr[x] = 0;
			arr[y] = 1;
		}
		else {
			arr[x] = 1;
			arr[y] = 0;
		}
	}
	for (j = 1; j <= 3; j++) if (arr[j] == 1) cout << j << "\n";
}