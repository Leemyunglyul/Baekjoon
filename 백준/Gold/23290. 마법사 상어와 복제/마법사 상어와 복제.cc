#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<map>

using namespace std;


int arr[5][5] = { 0 };
int fish[5][5][10] = { 0 };//1이 왼쪽 3이 위쪽 5가 오른쪽 7이 아래쪽
int sx, sy, magic;
bool visited[5][5];


int shark_move(int n1, int n2, int n3, int order, int r, int c) {
	int d, sum;
	if (order == 3) return 0;
	else if (order == 0) d = n1;
	else if (order == 1) d = n2;
	else d = n3;

	//상좌하우
	if (d == 1 && r > 1 ) {
		if (!visited[r - 1][c]) {
			visited[r - 1][c] = true;
			return fish[r - 1][c][0] + shark_move(n1, n2, n3, order + 1, r - 1, c);
		}
		else return shark_move(n1, n2, n3, order + 1, r - 1, c);
	}
	else if (d == 2 && c > 1) {
		if (!visited[r][c-1]) {
			visited[r][c-1] = true;
			return fish[r][c-1][0] + shark_move(n1, n2, n3, order + 1, r , c-1);
		}
		else return shark_move(n1, n2, n3, order + 1, r, c-1);
	}
	else if (d == 3 && r<4) {
		if (!visited[r + 1][c]) {
			visited[r + 1][c] = true;
			return fish[r+1][c ][0] + shark_move(n1, n2, n3, order + 1, r+1, c);
		}
		else return shark_move(n1, n2, n3, order + 1, r+1, c);
	}
	else if (d == 4 && c < 4 ) {
		if (!visited[r][c + 1]) {
			visited[r][c + 1] = true;
			return fish[r][c+1][0] + shark_move(n1, n2, n3, order + 1, r, c+1);
		}
		else return shark_move(n1, n2, n3, order + 1, r , c+1);
	}
	return -20000000;
}

void real_move(int d) {
	int k;
	//상좌하우
	if (d == 1) sx--;
	else if (d == 2) sy--;
	else if (d == 3) sx++;
	else if (d == 4) sy++;

	if (fish[sx][sy][0] > 0) arr[sx][sy] = 2;
	for (k = 0; k <= 8; k++) {
		fish[sx][sy][k] = 0;
	}
}

void cango(int r, int c, int d, int num, int tryn) {
	if (tryn == 8) {
		fish[r][c][d] += num;
		return;
	}
	if (d == 1) {
		if (c > 1 && arr[r][c - 1] == 0 && (r!=sx || c-1!=sy)) {
			fish[r][c - 1][d] += num;
		}
		else cango(r, c, 8, num, tryn + 1);
	}
	else if (d == 2) {
		if (c > 1 && r > 1 && arr[r - 1][c - 1] == 0 && (r-1 != sx || c - 1 != sy)) {
			fish[r - 1][c - 1][d] += num;
		}
		else cango(r, c, 1, num, tryn + 1);
	}
	else if (d == 3) {
		if (r > 1 && arr[r - 1][c] == 0 && (r-1 != sx || c  != sy)) {
			fish[r - 1][c][d] += num;
		}
		else cango(r, c, 2, num, tryn + 1);
	}
	else if (d == 4) {
		if (r > 1 && c < 4 && arr[r - 1][c + 1] == 0 && (r - 1 != sx || c+1 != sy)) {
			fish[r - 1][c + 1][d] += num;
		}
		else cango(r, c, 3, num, tryn + 1);
	}
	else if (d == 5) {
		if (c < 4 && arr[r][c + 1] == 0 && (r  != sx || c+1 != sy) ) {
			fish[r][c + 1][d] += num;
		}
		else cango(r, c, 4, num, tryn + 1);
	}
	else if (d == 6) {
		if (r < 4 && c < 4 && arr[r + 1][c + 1] == 0 && (r + 1 != sx || c +1!= sy) ) {
			fish[r + 1][c + 1][d] += num;
		}
		else cango(r, c, 5, num, tryn + 1);
	}
	else if (d == 7) {
		if (r < 4 && arr[r + 1][c] == 0 && (r + 1 != sx || c != sy)) {
			fish[r + 1][c][d] += num;
		}
		else cango(r, c, 6, num, tryn + 1);
	}
	else if (d == 8) {
		if (r < 4 && c>1 && arr[r + 1][c - 1] == 0 && (r + 1 != sx || c -1 != sy)) {
			fish[r + 1][c - 1][d] += num;
		}
		else cango(r, c, 7, num, tryn + 1);
	}
}

void fish_move() {
	int temp[5][5][10], i, j, k;
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 8; k++) {
				temp[i][j][k] = fish[i][j][k];
				fish[i][j][k] = 0;
			}
		}
	}
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 8; k++) {
				cango(i, j, k, temp[i][j][k], 0);
			}
		}
	}
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1, fish[i][j][0] = 0; k <= 8; k++) {
				fish[i][j][0] += fish[i][j][k];
			}
		}
	}
}

void op() {
	int temp[5][5][10], i, j, k, catchn, x, d1, d2, d3;
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 8; k++) {
				temp[i][j][k] = fish[i][j][k];
			}
		}
	}
	fish_move();
	for (i = 1, catchn=0, d1=0; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 4; k++) {
				fill_n(&visited[0][0], 5 * 5, false);
				int result = shark_move(i, j, k, 0, sx, sy);
				if (catchn < result || d1==0 ) {
					d1 = i;
					d2 = j;
					d3 = k;
					catchn = result;
				}
			}
		}
	}
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			if (arr[i][j] == 2) arr[i][j]++;
			else if (arr[i][j] == 3) arr[i][j] = 0;
		}
	}
	real_move(d1); real_move(d2); real_move(d3);
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1, fish[i][j][0] = 0; k <= 8; k++) {
				fish[i][j][k]+= temp[i][j][k];
				fish[i][j][0] += fish[i][j][k];
			}
		}
	}
}

void print() {
	cout << "물고기 냄새" << endl;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}cout << endl;
	cout << "물고기" << endl;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cout << fish[i][j][0] << " ";
		}
		cout << endl;
	}cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, fishn, fx, fy, d, k, sum;
	cin >> fishn >> magic;
	for (i = 0; i < fishn; i++) {
		cin >> fx >> fy >> d;
		fish[fx][fy][d]++;
	}
	cin >> sx >> sy;

	for (i = 0; i < magic; i++) {
		//cout << i + 1 << "번째" << endl;
		//cout << sx << " " << sy << endl;
		op();
		
		//print();
		//cout << sx << " " << sy << endl;
	}

	for (i = 1, sum=0; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 8; k++) {
				sum += fish[i][j][k];
			}
		}
	}
	cout << sum;
}