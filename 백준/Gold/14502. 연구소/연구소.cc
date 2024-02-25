#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int zone[9][9], row , col;
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;
queue<pair<int, int>> diff;

int bfs() {
	int num = 0;
	bool visited[9][9];
	fill_n(&visited[0][0], 9*9, false);
	for (int i = 0; i < virus.size(); i++) diff.push(virus[i]);
	while (!diff.empty()) {
		int x = diff.front().first;
		int y = diff.front().second;
		num++;
		diff.pop();

		if (x > 0 && zone[x - 1][y] == 0 && !visited[x-1][y]) {
			diff.push({ x - 1, y });
			visited[x - 1][y] = true;
		}
		if (y > 0 && zone[x][y - 1] == 0 && !visited[x][y - 1]) { 
			diff.push({ x , y - 1 });
			visited[x][y-1] = true;
		}
		if (x < row - 1 && zone[x + 1][y] == 0 && !visited[x + 1][y]) {
			diff.push({ x + 1, y });
			visited[x+1][y] = true;
		}
		if (y < col - 1 && zone[x][y + 1] == 0 && !visited[x][y+1]) {
			diff.push({ x, y + 1 });
			visited[x][y+1] = true;
		}
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, k, safety, walln;
	cin >> row >> col;
	for (i = 0, walln=0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> zone[i][j];
			if (zone[i][j] == 2) virus.push_back({ i, j });
			else if (zone[i][j] == 0) {
				wall.push_back({ i, j });
			}
			else walln++;
		}
	}
	for (i = 0, safety=0; i < wall.size(); i++) {
		zone[wall[i].first][wall[i].second] = 1;
		for (j = i+1; j < wall.size(); j++) {
			zone[wall[j].first][wall[j].second] = 1;
			for (k = j + 1; k < wall.size(); k++) {
				zone[wall[k].first][wall[k].second] = 1;
				safety = max(safety, int(row * col -bfs() - walln - 3));
				zone[wall[k].first][wall[k].second] = 0;
			}
			zone[wall[j].first][wall[j].second] = 0;
		}
		zone[wall[i].first][wall[i].second] = 0;
	}
	cout << safety;
}