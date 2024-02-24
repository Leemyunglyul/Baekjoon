#include<iostream>
#include<cstdlib>
#include<math.h>
#include<queue>

using namespace std;

int board[15][15] = { 0 };
int row, col, hole_row, hole_col, red_row, red_col, blue_row, blue_col, trynum, num;
queue<pair<int, pair<int, int>>> red_path;
queue<pair<int, int>> blue_path;

bool ob_between(int dir) {
	int big, small, i, j;
	if (dir==2 && red_row == blue_row) {
		big = max(red_col, blue_col);
		small = min(red_col, blue_col);
		for (i = small + 1; i < big; i++) if (board[red_row][i] == 5) return true;
		return false;
	}
	if (dir==1 && red_col == blue_col) {
		big = max(red_row, blue_row);
		small = min(red_row, blue_row);
		for (i = small + 1; i < big; i++) if (board[i][red_col] == 5) return true;
		return false;
	}
	return true;
}

int move(int dir) {
	int i, j;
	if (dir == 1 && ob_between(1)) {//위로 움직이는 데 둘 사이에 장애물이 있는 경우
		for (i = blue_row - 1; i > 0 ; i--) {
			if (board[i][blue_col] == 1) return -1;
			else if (board[i][blue_col] == 5) break;
		}
		for (j = red_row - 1; j > 0; j--) {
			if (board[j][red_col] == 1) return 1;
			else if (board[j][red_col] == 5) break;
		}
		//if (j + 1 == red_row) return -1;
		red_path.push({ num+1, {j+1 , red_col} });
		blue_path.push({ i+1, blue_col });
	}
	else if (dir == 1 && !ob_between(1)) {//위로 움직이는 데 둘 사이에 장애물이 없는 경우
		if (blue_row < hole_row && red_row > hole_row && red_col==hole_col) {
			for (i = red_row - 1; i > hole_row; i--) if (board[i][red_col] == 5) break;
			if(i==hole_row) return 1;
		}
		if (blue_row > red_row) {
			for (j = red_row - 1; j > 0; j--) {
				if (board[j][red_col] == 1) return -1;
				else if (board[j][red_col] == 5) break;
			}
			//if (j + 1 == red_row) return -1;
			red_path.push({ num+1, {j+1 , red_col} });
			blue_path.push({ j+2, blue_col });
		}		
		else {
			for (j = red_row - 1; j > 0; j--) {
				if (board[j][red_col] == 1) return -1;
				else if (board[j][red_col] == 5) break;
			}
			//if (j + 2 == red_row) return -1;
			red_path.push({ num+1, {j +2 , red_col} });
			blue_path.push({ j+1, blue_col });
		}
	}
	else if (dir == 2 && ob_between(2)) {//오른쪽으로 움직이는 데 둘 사이에 장애물이 있는 경우
		for (i = blue_col + 1; i <col-1; i++) {
			if (board[blue_row][i] == 1) return -1;
			else if (board[blue_row][i] == 5) break;
		}
		for (j = red_col + 1; j < col-1; j++) {
			if (board[red_row][j] == 1) return 1;
			else if (board[red_row][j] == 5) break;
		}
		//if (j - 1 == red_col) return -1;
		red_path.push({ num+1, {red_row , j-1} });
		blue_path.push({ blue_row, i-1 });
	}
	else if (dir == 2 && !ob_between(2)) {//오른쪽으로 움직이는 데 둘 사이에 장애물이 없는 경우
		if (blue_col > hole_col && red_col < hole_col && red_row == hole_row) {
			for (i = red_col + 1; i < hole_col; i++) if (board[red_row][i] == 5) break;
			if (i == hole_col) return 1;
		}
		if (blue_col < red_col) {
			for (j = red_col+ 1; j <col-1; j++) {
				if (board[red_row][j] == 1) return -1;//예외
				else if (board[red_row][j] == 5) break;
			}
			//if (j - 1 == red_col) return -1;
			red_path.push({ num + 1, {red_row , j-1} });
			blue_path.push({ blue_row, j-2 });
		}
		else {
			for (j = blue_col + 1; j < col - 1; j++) {
				if (board[red_row][j] == 1) return -1;//예외
				else if (board[red_row][j] == 5) break;
			}
			//if (j - 2 == red_col) return -1;
			red_path.push({ num + 1, {red_row , j - 2} });
			blue_path.push({ blue_row, j - 1 });
		}
	}
	else if (dir == 3 && ob_between(1)) {//아래로 움직이는 데 둘 사이에 장애물이 있는 경우
		for (i = blue_row + 1; i <row-1; i++) {
			if (board[i][blue_col] == 1) return -1;
			else if (board[i][blue_col] == 5) break;
		}
		for (j = red_row +1; j<row-1; j++) {
			if (board[j][red_col] == 1) return 1;
			else if (board[j][red_col] == 5) break;
		}
		//if (j - 1 == red_row) return -1;
		red_path.push({ num + 1, {j - 1 , red_col} });
		blue_path.push({ i - 1, blue_col });
	}
	else if (dir == 3 && !ob_between(1)) {//아래로 움직이는 데 둘 사이에 장애물이 없는 경우
		if (blue_row > hole_row && red_row < hole_row && red_col == hole_col) {
			for (i = red_row + 1; i < hole_row; i++) if (board[i][red_col] == 5) break;
			if (i == hole_row) return 1;
		}
		if (blue_row < red_row) {
			for (j = red_row + 1; j <row-1; j++) {
				if (board[j][red_col] == 1) return -1;
				else if (board[j][red_col] == 5) break;
			}
			//if (j - 1 == red_row) return -1;
			red_path.push({ num + 1, {j - 1 , red_col} });
			blue_path.push({ j - 2, blue_col });
		}
		else {
			for (j = red_row + 1; j < row - 1; j++) {
				if (board[j][red_col] == 1) return -1;
				else if (board[j][red_col] == 5) break;
			}
			//if (j - 2 == red_row) return -1;
			red_path.push({ num + 1, {j - 2 , red_col} });
			blue_path.push({ j - 1, blue_col });
		}
	}
	else if (dir == 4 && ob_between(2)) {//왼쪽으로 움직이는 데 둘 사이에 장애물이 있는 경우
		for (i = blue_col -1 ; i >0; i--) {
			if (board[blue_row][i] == 1) return -1;
			else if (board[blue_row][i] == 5) break;
		}
		for (j = red_col - 1; j >0; j--) {
			if (board[red_row][j] == 1) return 1;
			else if (board[red_row][j] == 5) break;
		}
		//if (j + 1 == red_col) return -1;
		red_path.push({ num + 1, {red_row , j + 1} });
		blue_path.push({ blue_row, i + 1 });
	}
	else if (dir == 4 && !ob_between(2)) {//왼쪽으로 움직이는 데 둘 사이에 장애물이 없는 경우
		if (blue_col<hole_col && red_col>hole_col && red_row == hole_row) {
			for (i = red_col - 1; i > hole_col; i--) if (board[red_row][i] == 5) break;
			if (i == hole_col) return 1;
		}
		if (blue_col > red_col) {
			for (j = red_col - 1; j >0; j--) {
				if (board[red_row][j] == 1) return -1;//예외
				else if (board[red_row][j] == 5) break;
			}
			//if (j + 1 == red_col) return -1;
			red_path.push({ num + 1, {red_row , j +1 } });
			blue_path.push({ blue_row, j + 2 });
		}
		else {
			for (j = blue_col - 1; j > 0; j--) {
				if (board[red_row][j] == 1) return -1;//예외
				else if (board[red_row][j] == 5) break;
			}
			//if (j + 2 == red_col) return -1;
			red_path.push({ num + 1, {red_row , j + 2} });
			blue_path.push({ blue_row, j + 1 });
		}
	}
	return 0;//다음 길로 가자
}

int bfs() {
	int i, j, result;
	while (!red_path.empty() && red_path.front().first<=9) {
		
		red_row = red_path.front().second.first;
		red_col = red_path.front().second.second;
		blue_row = blue_path.front().first;
		blue_col = blue_path.front().second;
		num = red_path.front().first;
		//cout << red_row<<" "<<red_col << "//"<<blue_row<<" " << blue_col << endl;
		red_path.pop();
		blue_path.pop();

		//board[red_row][red_col] = 2;
		//board[blue_row][blue_col] = 3;
		
		if (move(1) == 1) return num + 1;
		//cout << "////\n";
		if (move(3) == 1) return num + 1;
		//cout << "////\n";
		if (move(2) == 1) return num + 1;
		//cout << "////\n";
		if (move(4) == 1) return num + 1;
		//board[red_row][red_col] = 0;
		//board[blue_row][blue_col] = 0;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j;
	cin >> row >> col;
	char x;
	for (i = 0, trynum=-1; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> x;
			if (x == '#') board[i][j] = 5;
			else if (x == '.');
			else if (x == 'O') {
				board[i][j] = 1;
				hole_row = i;
				hole_col = j;
			}
			else if (x == 'R') {
				red_path.push({ 0,{ i, j} });
			}
			else if (x == 'B') {
				blue_path.push({ i, j});
			}
		}
	}
	cout << bfs();
}