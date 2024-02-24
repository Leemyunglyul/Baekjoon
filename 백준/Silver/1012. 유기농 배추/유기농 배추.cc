#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int arr[53][53] = {0};
queue<pair<int, int>> sab;

int bfs(int row, int col) {
	int i, j, match, x, y;
	for (i = 0, match=0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (arr[i][j] == 1) {
				sab.push({ i, j });
				match++;
				arr[i][j] = 0;
				while (!sab.empty()) {
					x = sab.front().first;
					y = sab.front().second;
					if (x > 0 && arr[x - 1][y] == 1) {
						sab.push({ x - 1, y });
						arr[x - 1][y] = 0;
					}
					if (y > 0 && arr[x][y - 1] == 1) {
						sab.push({ x , y - 1 });
						arr[x][y - 1] = 0;
					}
					if (x < row - 1 && arr[x + 1][y] == 1) {
						sab.push({ x + 1, y });
						arr[x+1][y] = 0;
					}
					if (y < col - 1 && arr[x][y + 1] == 1) {
						sab.push({ x , y + 1 });
						arr[x][y+1] = 0;
					}
					sab.pop();
				}
			}
		}
	}
	return match;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, i, j, n, row, col, worm, x, y;
	cin >> testn;
	while (testn--) {
		cin >> row >> col >> worm;
		for(i=0;i<worm;i++){
			cin >> x >> y;
			arr[x][y] = 1;
		}
		cout<< bfs(row, col)<<"\n";
	}
}