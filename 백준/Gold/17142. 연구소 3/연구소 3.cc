#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int lab[60][60], n, vn;
vector<pair<int, int>> virus;
queue<pair<int, pair<int, int>>> q;
vector<pair<int, pair<int, int>>> tt;
bool visited[60][60];
int result = 4000;

int bfs() {
	int big;
	int count = 0;
	int i, j;
	while (!q.empty()) {
		int r = q.front().second.first;
		int c = q.front().second.second;
		big = q.front().first;
		q.pop();

		if (r > 1 && lab[r - 1][c] != 1 && !visited[r - 1][c]) {
			visited[r - 1][c] = true;
			q.push({ big + 1, {r - 1, c} });
			if (lab[r - 1][c] == 0) count=big+1;
		}
		if (c > 1 && lab[r][c-1] != 1 && !visited[r ][c-1]) {
			visited[r ][c-1] = true;
			q.push({ big + 1, {r , c-1} });
			if (lab[r][c-1] == 0) count = big + 1;
		}
		if (r <n && lab[r + 1][c] != 1 && !visited[r + 1][c]) {
			visited[r + 1][c] = true;
			q.push({ big + 1, {r + 1, c} });
			if (lab[r+1][c] == 0) count = big + 1;
		}
		if (c < n && lab[r][c + 1] != 1 && !visited[r][c + 1]) {
			visited[r][c + 1] = true;
			q.push({ big + 1, {r , c + 1} });
			if (lab[r][c+1] == 0) count = big + 1;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (!visited[i][j] && lab[i][j] == 0) return -1;
		}
	}
	return count;
}

void put(int x, int num) {
	int i;
	if (num == vn) {
		fill_n(&visited[0][0], 60 * 60, false);
		for (i = 0; i < vn; i++) {
			q.push(tt[i]);
			visited[tt[i].second.first][tt[i].second.second] = true;
		}
		int temp = bfs();
		if (temp >= 0) result = min(result, temp);
		return;
	}
	
	for (i = x; i < virus.size(); i++) {
		tt.push_back({ 0,  virus[i] });
		put(i+1, num + 1);
		tt.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> vn;
	int i, j, k;
	for (i = 1, result=4000; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virus.push_back({ i, j });
		}
	}
	put(0, 0);
	if (result == 4000) cout << "-1";
	else cout << result;
}