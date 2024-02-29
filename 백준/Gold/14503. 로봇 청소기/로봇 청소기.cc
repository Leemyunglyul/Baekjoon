#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int row, col, rx, ry, dir, sum;
int room[53][53] = {0};

bool to_clean(int r, int c) {
	if (room[r - 1][c] == 0 || room[r][c - 1] == 0 ||
		room[r + 1][c] == 0 || room[r][c + 1] == 0) return true;
	else return false;
}

void rot() {
	if (dir > 0) dir--;
	else dir = 3;
}

void clean() {
	while (1) {
		if (room[rx][ry] == 0) {
			room[rx][ry] = 2;
			sum++;
		}
		if (!to_clean(rx, ry)) {
			if (dir == 0 && room[rx + 1][ry] != 1) rx++;
			else if (dir == 1 && room[rx][ry - 1] != 1) ry--;
			else if (dir == 2 && room[rx - 1][ry] != 1) rx--;
			else if (dir == 3 && room[rx][ry + 1] != 1) ry++;
			else return;
		}
		else {
			rot();
			if (dir == 0 && room[rx - 1][ry] == 0) rx--;
			else if (dir == 1 && room[rx][ry + 1] == 0) ry++;
			else if (dir == 2 && room[rx + 1][ry] == 0) rx++;
			else if (dir == 3 && room[rx][ry - 1] == 0) ry--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col;
	int i, j;
	cin >> rx >> ry >> dir;
	for (i = 0, sum=0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> room[i][j];
		}
	}
	clean();
	cout << sum;
}