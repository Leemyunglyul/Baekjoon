#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int board[53][53], row, col;
bool visited[53][53];
queue<pair<int, int>> q;
queue<pair<int, int>> eras;

void rot(int row, int go) {
	int i;
	vector<int> x;
	x.push_back(0);
	for (i = col-go+1; i <= col; i++) {
		x.push_back(board[row][i]);
	}
	for (i = col-go; i >=1; i--) board[row][i + go] = board[row][i];
	for (i = 1; i <= go; i++) board[row][i] = x[i];
}

void bfs(int target) {
	int i;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		eras.push({ x, y });

		q.pop();

		if (x > 1 && target == board[x - 1][y] && !visited[x-1][y]) {
			visited[x - 1][y] = true;
			q.push({ x - 1, y });
		}
		if (y > 1 && target == board[x][y - 1] && !visited[x][y - 1]) {
			visited[x][y-1] = true;
			q.push({ x, y-1 });
		}
		if (x<row && target == board[x+1][y] && !visited[x+1][y ]) {
			visited[x+1][y] = true;
			q.push({ x+1, y});
		}
		if (y < col && target == board[x][y+1] && !visited[x ][y+1]) {
			visited[x ][y+1] = true;
			q.push({ x , y +1});
		}
		if (y == 1 && target == board[x][col] && !visited[x][col]) {
			visited[x][col] = true;
			q.push({ x, col });
		}
		else if (y == col && target == board[x][1] && !visited[x][1]) {
			visited[x][1] = true;
			q.push({ x, 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tryn, i, j, x, d, k, sum, l, rearr, num;
	cin >> row >> col >> tryn;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			cin >> board[i][j];
		}
	}
	for (l = 0; l < tryn; l++) {
		cin >> x >> d >> k;
		if (d == 1) k = col - k;
		for (j = 1; j <= row; j++) {
			if (j % x == 0) rot(j, k);
		}
		/*for (i = 1, sum = 0; i <= row; i++) {
			for (j = 1; j <= col; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}*/
		fill_n(&visited[0][0], 53 * 53, false);
		for (i = 1, rearr=0; i <= row; i++) {
			for (j = 1; j <= col; j++) {
				if (board[i][j] == -1);
				else if (visited[i][j]);
				else {
					visited[i][j] = true;
					q.push({ i, j });
					bfs(board[i][j]);
					if (eras.size() == 1) eras.pop();
					else {
						rearr = 1;
						while (!eras.empty()) {
							board[eras.front().first][eras.front().second] = -1;
							eras.pop();
						}
					}
				}
			}
		}
		if (rearr == 0) {
			for (i = 1, sum = 0, num=0; i <= row; i++) {
				for (j = 1; j <= col; j++) {
					if (board[i][j] > 0) {
						sum += board[i][j];
						num++;
					}
				}
			}
			double avg = double( sum )/ num;
			for (i = 1; i <= row; i++) {
				for (j = 1; j <= col; j++) {
					if (board[i][j] == -1) continue;
					if (avg < double(board[i][j])) board[i][j]--;
					else if(avg > double(board[i][j])) board[i][j]++;
				}
			}
		}
	}
	for (i = 1, sum = 0; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			if (board[i][j] >= 0) sum += board[i][j];
			//cout << board[i][j] << " ";
		}
		//cout << endl;
	}
	cout << sum;
}