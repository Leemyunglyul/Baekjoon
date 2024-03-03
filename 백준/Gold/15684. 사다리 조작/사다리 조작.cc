#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int lad[40][20] = { 0 };
int col, row, ln;

bool find() {
	int i, j;
	for (i = 1; i <= col; i++) {
		int pos = i;
		for (j = 1; j <= row; j++) {
			if (lad[j][pos] == 1 ) {//오른쪽
				pos++;
			}
			else if (pos > 1 && lad[j][pos - 1] == 1) {//왼쪽
				pos--;
			}
		}
		if (pos != i) return false;
	}
	return true;
}

bool new_lad(int num, int goal, int r, int c) {
	if (num == goal) {
		if (find()) return true;
		else return false;
	}
	int i, j;
	if (num == 0) {
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= col; j++) {
				if (lad[i][j] == 1) continue;
				if (j < col && lad[i][j + 1] == 1) continue;
				lad[i][j] = 1;
				if (new_lad(num + 1, goal, i, j)) return true;
				lad[i][j] = 0;
			}
		}
		return false;
	}
	for (j = c+2; j <= col; j++) {
		if (lad[r][j] == 1) continue;
		if (j < col && lad[r][j + 1] == 1) continue;
		lad[r][j] = 1;
		if (new_lad(num + 1, goal, r, j)) return true;
		lad[r][j] = 0;
	}
	for (i = r+1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			if (lad[i][j] == 1) continue;
			if (j < col && lad[i][j + 1] == 1) continue;
			lad[i][j] = 1;
			if (new_lad(num + 1, goal, i, j)) return true;
			lad[i][j] = 0;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> col >> ln >> row;
	int i, j,  r, c;
	for (i = 0; i < ln; i++) {
		cin >> r >> c;
		lad[r][c] = 1;
	}
	if (new_lad(0, 0, 1, 1)) cout << "0";
	else if (new_lad(0, 1, 1, 1)) cout << "1";
	else if (new_lad(0, 2, 1, 1)) cout << "2";
	else if (new_lad(0, 3, 1, 1)) cout << "3";
	else cout << "-1";
}