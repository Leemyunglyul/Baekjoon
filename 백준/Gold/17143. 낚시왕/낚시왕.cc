#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int sink[110][110] = { 0 };
int shark[11000][6], row, col, sharkn;

void exist(int n) {
	if (sink[shark[n][1]][shark[n][2]] != 0) {//다른 상어 존재시
		if (shark[sink[shark[n][1]][shark[n][2]]][5] > shark[n][5]) {
			shark[n][0] = 0;
		}
		else {
			shark[sink[shark[n][1]][shark[n][2]]][0] = 0;
			sink[shark[n][1]][shark[n][2]] = n;
		}
	}
	else {// 다른상어 없으면.
		sink[shark[n][1]][shark[n][2]] = n;
	}
}

void move(int n, int speed) {
	if (shark[n][4] == 1) {
		if (speed <= shark[n][1] - 1) {//초과 X
			shark[n][1] -= speed;
			exist(n);
		}
		else {//초과
			speed = speed - (shark[n][1] - 1);
			shark[n][1] = 1;
			shark[n][4] = 2;
			move(n, speed);
		}
	}
	else if (shark[n][4] == 2) {
		if (speed <= row- shark[n][1]) {//초과 X
			shark[n][1] += speed;
			exist(n);
		}
		else {//초과
			speed = speed - (row - shark[n][1]);
			shark[n][1] = row;
			shark[n][4] = 1;
			move(n, speed);
		}
	}
	else if (shark[n][4] == 3) {
		if (speed <= col - shark[n][2]) {//초과 X
			shark[n][2] += speed;
			exist(n);
		}
		else {//초과
			speed = speed - (col - shark[n][2]);
			shark[n][2] = col;
			shark[n][4] = 4;
			move(n, speed);
		}
	}
	else if (shark[n][4] == 4) {
		if (speed <= shark[n][2] - 1) {//초과 X
			shark[n][2] -= speed;
			exist(n);
		}
		else {//초과
			speed = speed - (shark[n][2]-1);
			shark[n][2] = 1;
			shark[n][4] = 3;
			move(n, speed);
		}
	}
}

void shark_move() {
	int i;
	for (i = 1; i <= sharkn; i++) {//초기화
		if(shark[i][0]) sink[shark[i][1]][shark[i][2]] = 0;
	}
	for (i = 1; i <= sharkn; i++) {
		if (shark[i][0] == 0) continue;
		move(i, shark[i][3]);
	}
}

void print() {
	int i, j;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			cout << sink[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int fishing() {
	int i, j, sum;
	for (i = 1, sum=0; i <= col; i++) {
		for (j = 1; j <= row; j++) {
			if (sink[j][i] > 0) {
				sum += shark[sink[j][i]][5];
				shark[sink[j][i]][0] = 0;
				sink[j][i] = 0;
				break;
			}
		}
		//cout << i << "번째 상황" << endl;
		//print();
		shark_move();
		//print();
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row >> col >> sharkn;
	int i;
	for (i = 1; i <= sharkn; i++) {
		cin >> shark[i][1] >> shark[i][2] >> shark[i][3] >> shark[i][4]>> shark[i][5];
		//위치, 위치, 속력, 방향, 크기
		// 1 위, 2 아래, 3 오른쪽, 4 왼쪽
		shark[i][0] = 1;
		sink[shark[i][1]][shark[i][2]] = i;
	}
	cout << fishing();
}