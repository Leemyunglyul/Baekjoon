#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int pop[30][30] = { 0 };
bool visited[30][30];
int p1, p2, p3, p4, p5 , n, d1, d2;

bool sat(int r, int c) {
	if (r + d1 + d2 <= n && c - d1 >= 1 && c + d2 <= n) return true;
	else return false;
}

bool zone(int dir, int x, int y, int r, int c) {
	if (dir == 1) {
		if (r < x + d1 && c <= y) return true;
	}
	else if (dir == 2) {
		if (r <= x + d2 && c > y) return true;
	}
	else if (dir == 3) {
		if (r >= x + d1 && c < y - d1 + d2) return true;
	}
	else if (dir == 4) {
		if (r > x + d2 && c >= y - d1 + d2) return true;
	}
	return false;
}


int cal_pop(int x, int y, int dir) {
	queue<pair<int, int>> q;
	if (dir == 1) q.push({ 1, 1 });
	else if (dir == 2) q.push({ 1, n });
	else if (dir == 3) q.push({ n , 1 });
	else q.push({ n, n });

	visited[q.front().first][q.front().second] = true;

	int sum = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		sum += pop[r][c];

		q.pop();

		if (r > 1 && !visited[r - 1][c] && zone(dir, x, y, r - 1, c)) {
			visited[r - 1][c] = true;
			q.push({ r - 1, c });
		}
		if (c > 1 && !visited[r ][c - 1] && zone(dir, x, y, r , c- 1)) {
			visited[r ][c -1] = true;
			q.push({ r , c- 1 });
		}
		if (r< n && !visited[r+1][c] && zone(dir, x, y, r+1, c )) {
			visited[r+1][c] = true;
			q.push({ r +1, c  });
		}
		if (c < n && !visited[r ][c+1] && zone(dir, x, y, r , c+1)) {
			visited[r ][c+1] = true;
			q.push({ r, c +1});
		}
	}
	return sum;
}

int cal_pop5() {
	int i, j, sum;
	for (i = 1, sum=0; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (!visited[i][j]) sum += pop[i][j];
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int i, j, k, least, s;
	for (i = 1, s = 0; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> pop[i][j];
			//s += pop[i][j];
		}
	}//cout << s << endl;
	for (i = 1, least=n*n*1000; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (d1 = 1; d1 <= n; d1++) {
				for (d2 = 1; d2 <= n; d2++) {
					if (!sat(i, j)) continue;
					fill_n(&visited[0][0], 30 * 30, false);
					p1 = 0; p2 = 0; p3 = 0; p4 = 0; p5 = 0;
					for (k = 0; k <= d1; k++) {
						if (!visited[i+k][j-k]) p5 += pop[i + k][j - k];
						visited[i + k][j - k] = true;
						if (!visited[i + d2 + k][j + d2 - k]) p5 += pop[i + d2 + k][j + d2 - k];
						visited[i + d2 + k][j + d2 - k] = true;
					}
					for (k = 0; k <= d2; k++) {
						if(!visited[i + k][j + k]) p5 += pop[i + k][j + k];
						visited[i + k][j + k] = true;
						if (!visited[i + d1 + k][j - d1 + k]) p5 += pop[i + d1 + k][j - d1 + k];
						visited[i + d1 + k][j - d1 + k] = true;
					}
					p1 = cal_pop(i, j, 1);
					p2 = cal_pop(i, j, 2);
					p3 = cal_pop(i, j, 3);
					p4 = cal_pop(i, j, 4);
					p5 += cal_pop5();

					int big = max(max(p1, p2), max(p3, max(p4, p5)));
					int small = min(min(p1, p2), min(p3, min(p4, p5)));	
					//cout << i << " " << j << "//" << d1 << " " << d2 << "//" << big - small << endl;
					//cout << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << endl;
					least = min(least, big - small);
				}
			}
		}
	}
	cout << least;
}