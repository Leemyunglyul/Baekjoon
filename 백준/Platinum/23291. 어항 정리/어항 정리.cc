#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>

using namespace std;

int turn = 0;
int line[200];
int board[200][200] = {0};
int temp[200][200] = { 0 };
bool visited[200][200] = { 0 };
int n, lim;

void line1(int start, int end, int height, int h1, int h2) {
	int i, j, now;
	int tem[120];//복사 직선.
	for (i = start; i <= end; i++) {
		tem[i - start + 1] = board[100][i];
	}
	for (i = h1, now = 1; i <= h2; i++) {
		for (j = 100; j >= height; j--) {
			line[now++] = board[j][i];
		}
	}
	for (; now <= n; now++) {
		line[now] = board[100][start++];
	}
}

void control1(int start, int end, int height, int h1, int h2) {
	fill_n(&temp[0][0], 200 * 200, 0);
	int i, j, diff;
	fill_n(&visited[0][0], 200 * 200, false);
	for (i = height; i <= 100; i++) {
		for (j = 1; j <= end; j++) {
			if (board[i][j] == 0) continue;
			visited[i][j] = true;
			if (i > height && board[i - 1][j] != 0 && !visited[i-1][j]) {
				diff = abs(board[i - 1][j] - board[i][j]);
				if (board[i - 1][j] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i-1][j] -= diff / 5;
				}
				else {
					temp[i-1][j] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
			if (i <100 && board[i + 1][j] != 0 && !visited[i + 1][j]) {
				diff = abs(board[i + 1][j] - board[i][j]);
				if (board[i + 1][j] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i + 1][j] -= diff / 5;
				}
				else {
					temp[i + 1][j] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
			if (j < end && board[i][j+1] != 0 && !visited[i][j+1]) {
				diff = abs(board[i][j+1] - board[i][j]);
				if (board[i ][j+1] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i][j + 1] -= diff / 5;
				}
				else {
					temp[i][j+1] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
			if (j > 1 && board[i][j-1] != 0 && !visited[i][j-1]) {
				diff = abs(board[i][j - 1] - board[i][j]);
				if (board[i][j - 1] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i][j - 1] -= diff / 5;
				}
				else {
					temp[i][j - 1] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
		}
	}
	for (i = height; i <= 100; i++) {
		for (j = 1; j <= end; j++) {
			if (board[i][j] == 0) continue;
			board[i][j] += temp[i][j];
		}
	}

	line1(start, end, height, h1, h2);
}

void control2() {
	fill_n(&visited[0][0], 200 * 200, false);
	fill_n(&temp[0][0], 200 * 200, 0);
	int i, j, diff, now;
	for (i = 97; i <= 100; i++) {
		for (j = 1; j <= n / 4; j++) {
			visited[i][j] = true;
			if (i > 97 && board[i - 1][j] != 0 && !visited[i-1][j]) {
				diff = abs(board[i - 1][j] - board[i][j]);
				if (board[i - 1][j] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i - 1][j] -= diff / 5;
				}
				else {
					temp[i - 1][j] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
			if (i < 100 && board[i + 1][j] != 0 && !visited[i + 1][j]) {
				diff = abs(board[i + 1][j] - board[i][j]);
				if (board[i + 1][j] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i + 1][j] -= diff / 5;
				}
				else {
					temp[i + 1][j] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
			if (j < n/4 && board[i][j + 1] != 0 && !visited[i][j+1]) {
				diff = abs(board[i][j + 1] - board[i][j]);
				if (board[i][j + 1] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i][j + 1] -= diff / 5;
				}
				else {
					temp[i][j + 1] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
			if (j > 1 && board[i][j - 1] != 0 && !visited[i][j-1]) {
				diff = abs(board[i][j - 1] - board[i][j]);
				if (board[i][j - 1] > board[i][j]) {
					temp[i][j] += diff / 5;
					temp[i][j - 1] -= diff / 5;
				}
				else {
					temp[i][j - 1] += diff / 5;
					temp[i][j] -= diff / 5;
				}
			}
		}
	}
	for (i = 97; i <= 100; i++) {
		for (j = 1; j <= n / 4; j++) {
			board[i][j] += temp[i][j];
		}
	}
	//for (j = 97; j <= 100; j++) {
		//for (i = 1; i <= n/4; i++) {
			//cout << board[j][i] << " ";
		//}cout << endl;
	//}
	for (i = 1, now = 1; i <=n/4; i++) {
		for (j = 100; j >= 97; j--) {
			line[now++] = board[j][i];
		}
	}
}

void op1(int start, int end, int height, int h1, int h2) {
	int i, j, r, c;
	if (start == 2 && height==100) {
		fill_n(&board[0][0], 200 * 200, 0);
		for (i = 2; i <= n; i++) {
			board[100][i - 1] = line[i];
		}
		board[99][1] = line[1];
		op1(2, n - 1, 99, 1, 1);
		return;
	}
	int tem[120] = {0};//복사 직선.
	for (i = start; i <= end; i++) {
		tem[i - start+1] = board[100][i];
	}
	vector<vector<int>> x;
	vector<int> y;
	for (i = h1; i <= h2; i++) {//돌리기
		for (j = 100; j >= height; j--) {
			y.push_back(board[j][i]);
		}
		x.push_back(y);
		y.clear();
	}
	fill_n(&board[0][0], 200 * 200, 0);
	for (i = 1; i <= end - start + 1; i++) {
		board[100][i] = tem[i];
	}
	for (i = 1, r=x.size()-1; i <= h2 - h1 + 1; i++, r--) {
		for (j = 1, c=0; j <= 100 - height + 1; j++, c++) {
			board[100-i][j] = x[r][c];
		}
	}
	h1 = 1;
	h2 = 100 - height + 1;
	height = 100-x.size();
	end = end - start + 1;
	start = h2 + 1;


	if (100-height+1 > end - start + 1) {
		control1(start, end, height, h1, h2);
	}
	else {
		op1(start, end, height, h1, h2);
	}
}

void op2() {
	int i, start, end, j;
	int d1 = n / 2;
	int temp1[110];
	start = d1 + 1;
	end = n;
	for (i = 1; i <= d1; i++) {
		temp1[i] = line[i];
	}
	for (i = start; i <= end; i++) {
		board[100][i - start + 1] = line[i];
	}
	for (i = 1; i <=d1; i++) {
		board[99][i] = temp1[d1 + 1 - i];
	}
}

void op3() {
	int i, start, end, j;
	int d1 = n / 4;
	int temp1[2][60];
	start = d1 + 1;
	end = n/2;
	for (i = 100; i >=99; i--) {
		for (j = d1; j >=1; j--) {
			if(i==100) board[97][d1+1-j] = board[i][j];
			else board[98][d1 + 1 - j] = board[i][j];
		}
	}
	for (i = start; i <= end; i++) {
		for (j = 99; j <= 100; j++) {
			board[j][i-d1] = board[j][i];
			board[j][i] = 0;
		}
	}
	
}

bool end_check() {//k이하인지 검사
	int i, mint, maxt;
	for (i = 2, mint=line[1], maxt=line[1]; i <= n; i++) {
		mint = min(mint, line[i]);
		maxt = max(maxt, line[i]);
	}
	if (maxt - mint <= lim) return true;
	else return false;
}

void plust() {
	int i, mint;
	for (i = 2, mint=line[1]; i <= n; i++) {
		mint = min(mint, line[i]);
	}
	for (i = 1; i <= n; i++) {
		if (line[i] == mint) line[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> lim;
	int i;
	for (i = 1; i <= n; i++) cin >> line[i];
	for (turn = 0;1;) {
		if (end_check()) break;
		turn++;
		plust();
		op1(2, n, 100, 1, 1);
		op2();
		op3();
		control2();
		//for (i = 1, cout << turn << "번째" << endl; i <= n; i++) {
			//cout << line[i] << " ";
		//}cout << endl;
	}
	cout << turn;
}