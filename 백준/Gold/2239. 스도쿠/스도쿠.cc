#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int b[10][10];
vector<pair<int, int>> blank;

int bb(int x) {
	if (x>=1 && x<= 3) return 1;
	else if (x>=4 && x <= 6) return 2;
	else return 3;
}

bool go(int row, int col) {
	int i, j;
	int temp = b[row][col];
	for (i = bb(row) * 3 - 2; i <= bb(row)*3; i++) {
		for (j = bb(col) * 3 - 2; j <= bb(col)*3; j++) {
			if (i == row && j == col) continue;
			if (b[i][j]>0 && temp == b[i][j]) return false;
		}
	}
	for (i = 1; i <= 9; i++) {
		if (row == i ) continue;
		if (b[i][col] == 0) continue;
		if (temp == b[i][col]) return false;
	}
	for (i = 1; i <= 9; i++) {
		if (col == i) continue;
		if (b[row][i] == 0) continue;
		if (temp == b[row][i]) return false;
	}
	return true;
}

int backtrack(int now) {
	int i, j;
	if (now == blank.size()) {
		for (i = 1; i <= 9; i++) {
			for (j = 1; j <= 9; j++) {
				cout << b[i][j];
			}
			cout << "\n";
		}
		return 1;
	}
	for (i = 1; i <= 9; i++) {
		b[blank[now].first][blank[now].second] = i;
		if (go(blank[now].first, blank[now].second)) {
			if(backtrack(now + 1)==1) return 1;
		}
	}
	for (i = now; i < blank.size(); i++) {
		b[blank[i].first][blank[i].second] = 0;
	}
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j;
	char x;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			cin >> x;
			b[i][j] = x - 48;
			if (b[i][j] == 0) blank.push_back({ i, j });

		}
	}
	backtrack(0);
    return 0;
}