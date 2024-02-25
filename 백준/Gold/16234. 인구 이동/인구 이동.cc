#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;
int p[53][53];
bool visited[53][53];
queue<pair<int, int>> diff;
queue<pair<int, int>> list;
int lb, ub, n, pop, num;

bool df(int x, int y) {
	if (abs(x - y) >= lb && abs(x - y) <= ub) return true;
	else return false;
}

void bfs() {
	while (!diff.empty()) {
		list.push(diff.front());
		int x = diff.front().first;
		int y = diff.front().second;
		diff.pop();
		num++;
		pop += p[x][y];

		//cout << x<<" " << y << "// " << num << endl;
		if (x > 0 && df(p[x][y], p[x - 1][y]) && !visited[x - 1][y]) {
			visited[x - 1][y] = true;
			diff.push({ x - 1, y });
		}
		if (y > 0 && df(p[x][y], p[x ][y-1]) && !visited[x][y-1]) {
			visited[x][y-1] = true;
			diff.push({ x , y-1 });
		}
		if (x <n-1 && df(p[x][y], p[x+1][y]) && !visited[x+1][y]) {
			visited[x+1][y] = true;
			diff.push({ x +1 , y });
		}
		if (y < n - 1 && df(p[x][y], p[x][y+1]) && !visited[x][y+1]) {
			visited[x][y+1] = true;
			diff.push({ x , y+1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> lb >> ub;
	int i, j, sum, yes;
	for (i = 0, sum=0; i < n; i++) {
		for (j = 0; j < n; j++) cin >> p[i][j];
	}
	while (1) {
		fill_n(&visited[0][0], 53 * 53, false);
		for (i = 0, yes=0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				pop = 0;
				num = 0;
				visited[i][j] = true;
				diff.push({ i, j });
				bfs();
				if (num > 1) {
					yes = 1;
				}
				while (!list.empty()) {
					int x = list.front().first;
					int y = list.front().second;
					list.pop();
					p[x][y] = pop / num;
				}
			}
		}
		if (yes == 0) break;
		else sum++;
	}
	cout << sum;
}