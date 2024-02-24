#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int arr[110][110] = {0};
int d[110][110] = { 0 };
queue<pair<int, pair<int, int>>> sab;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, i, j, n, row, col, match, x, y;
	char k;
	cin >> row >> col;
	for (i = 0, match=0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> k;
			//d[i][j] = row * col;
			arr[i][j] = k - 48;;
		}
	}
	sab.push({ 0, {0, 0} });
	arr[0][0] = 0;
	while (!sab.empty()) {
		x = sab.front().second.first;
		y = sab.front().second.second;
		match = sab.front().first + 1;
		if (x > 0 && arr[x - 1][y] == 1) {
			sab.push({ match,{ x - 1, y } });
			arr[x - 1][y] = 0;
			d[x - 1][y] = match;
		}
		if (y > 0 && arr[x][y - 1] == 1) {
			sab.push({ match,{ x, y-1 } });
			d[x][y-1] = match;
			arr[x][y - 1] = 0;
		}
		if (x < row - 1 && arr[x + 1][y] == 1) {
			sab.push({ match,{ x+1, y } });
			d[x+1][y] = match;
			arr[x + 1][y] = 0;
		}
		if (y < col - 1 && arr[x][y + 1] == 1) {
			sab.push({ match,{ x, y + 1 } });
			d[x][y + 1] = match;
			arr[x][y + 1] = 0;
		}
		sab.pop();
	}
	cout << d[row-1][col-1]+1 << "\n";
}