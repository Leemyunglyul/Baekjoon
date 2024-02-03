#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

int sum=0;
int row, col;
int arr[1010][1010];
vector<pair<int, int>> xq;

int road(int x, int y) {
	int dir = arr[x][y];
	int anw;
	if (dir == -1) {
		return 1;
	}
	arr[x][y] = -1;
	xq.push_back({ x, y });
	if (dir == 1) {
		if (arr[x-1][y]==0) {
			return 0;
		}
		anw= road(x - 1, y);
		return anw;
	}
	else if (dir == 2) {
		if (arr[x + 1][y] == 0) {
			return 0;
		}
		anw= road(x + 1, y);
		return anw;
	}
	else if (dir == 3) {
		if (arr[x][y-1] == 0) {
			return 0;
		}
		anw = road(x, y - 1);
		return anw;
	}
	else if (dir== 4) {
		if (arr[x][y + 1] == 0) {
			return 0;
		}
		anw= road(x, y + 1);
		return anw;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, k;
	char c;
	cin >> row >> col;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> c;
			if (c == 'U') arr[i][j] = 1;
			else if (c == 'D') arr[i][j] = 2;
			else if (c == 'L') arr[i][j] = 3;
			else arr[i][j] = 4;
		}
	}
	for (i = 0, sum=0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (arr[i][j] == 0) continue;
			if (road(i, j) == 1) sum++;
			for (k = 0; k < xq.size(); k++) {
				arr[xq[k].first][xq[k].second] = 0;
			}
			xq.clear();
		}
	}
	cout << sum;
}