#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>

using namespace std;

int board[16][16];//보드판
int n, cn;
vector<int> chess[200];//보드판에서 말이 어떻게 쌓여있는지.
vector<pair<int, int>> pos;//각 말의 위치
int dir[20];
int turn = 1;

int position(int r, int c) {
	return (r - 1) * n + c;
}

void together(int num, int gr, int gc) {//업고 이동
	int r = pos[num].first;
	int c = pos[num].second;
	int p = position(r, c);
	int i, j;
	for (i = 0; i < chess[p].size(); i++) {//체스말 찾기
		if (chess[p][i] == num) break;
	}
	//목표 칸이 빨간색인 경우 뒤집기
	if (board[gr][gc] == 1) {
		for (j = chess[p].size()-1; j >=i; j--) {//위에있는 말 같이 이동
			chess[position(gr, gc)].push_back(chess[p][j]);
			pos[chess[p][j]] = { gr, gc };
		}
	}
	//하얀 칸
	else {
		for (j = i; j < chess[p].size(); j++) {//위에있는 말 같이 이동
			chess[position(gr, gc)].push_back(chess[p][j]);
			pos[chess[p][j]] = { gr, gc };
		}
	}
	chess[p].erase(chess[p].begin()+i, chess[p].end());//원래 있던 칸의 말들은 삭제
	if (chess[position(gr, gc)].size() >= 4) {
		cout << turn;
		exit(0);
	}
}

void c_move(int num) {//이동방향: 우,좌,상,하 1234
	int r = pos[num].first;
	int c = pos[num].second;
	int d = dir[num];
	if (d == 1) {//우
		//이동칸 벽,이동칸 파란색
		if (c == n ||(c < n && board[r][c + 1] == 2)) {
			dir[num] = 2;
			//반대방향도 파란이면 멈추기, 혹은 벽
			if (c==1|| board[r][c - 1] == 2) {
				return;
			}
			//아니면 한칸 이동
			else {
				//만약 4개이상 쌓이면 종료
				together(num, r, c - 1);
			}
		}
		else {
			together(num, r, c + 1);
		}
	}
	else if (d == 2) {//좌
		//이동칸 벽,이동칸 파란색
		if (c == 1 || (c >1 && board[r][c - 1] == 2)) {
			dir[num] = 1;
			//반대방향도 파란이면 멈추기, 혹은 벽
			if (c == n || board[r][c + 1] == 2) {
				return;
			}
			//아니면 한칸 이동
			else {
				//만약 4개이상 쌓이면 종료
				together(num, r, c + 1);
			}
		}
		else {//좌로 이동
			together(num, r, c - 1);
		}
	}
	else if (d == 3) {//상
		//이동칸 벽,이동칸 파란색
		if (r == 1 || (r > 1 && board[r-1][c] == 2)) {
			dir[num] = 4;
			//반대방향도 파란이면 멈추기, 혹은 벽
			if (r==n || board[r+1][c] == 2) {
				return;
			}
			//아니면 한칸 이동
			else {
				//만약 4개이상 쌓이면 종료
				together(num, r+1, c);
			}
		}
		else {//위로 이동
			together(num, r-1, c );
		}
	}
	else if (d == 4) {//하
		//이동칸 벽,이동칸 파란색
		if (r == n || (r <n && board[r + 1][c] == 2)) {
			dir[num] = 3;
			//반대방향도 파란이면 멈추기, 혹은 벽
			if (r == 1 || board[r - 1][c] == 2) {
				return;
			}
			//아니면 한칸 이동
			else {
				//만약 4개이상 쌓이면 종료
				together(num, r - 1, c);
			}
		}
		else {//아래로 이동
			together(num, r + 1, c);
		}
	}
}

void chess_move() {
	if (turn > 1000) {
		cout << "-1";
		return;
	}
	int i;
	for (i = 1; i <= cn; i++) {
		c_move(i);
	}
	turn++;
	chess_move();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> cn;
	int i, j, r, c, d;
	for (i = 1; i <= n; i++) {//보드판 입력
		for (j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	pos.push_back({ 0, 0 });//dummy
	for (i = 1; i <= cn; i++) {//체스말 입력/행,열, 이동방향
		//이동방향: 우,좌,상,하 1234
		cin >> r >> c >> d;
		chess[position(r, c)].push_back(i);
		pos.push_back({ r, c });
		dir[i] = d;
	}
	chess_move();
}