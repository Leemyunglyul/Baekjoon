#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

queue<pair<int, int>> q;
queue<pair<int, int>> temp;
int arr[1001][1001];
int t0 = 0;
int t1 = 0;
int t2 = 0;
int num;
int date=0;
int n, m;

void bfs() {
	int x, y;
	while (1) {
		date++;
		while (q.empty() == 0) {
			x = q.front().first;
			y = q.front().second;
			arr[x][y] = 1;
			q.pop();
			if (x > 0 && arr[x - 1][y] == 0) {
				temp.push({ x - 1, y });
				arr[x - 1][y] = 2;
				t1--;
				t2++;
			}
			if (x < n - 1 && arr[x + 1][y] == 0) {
				temp.push({ x + 1, y });
				arr[x +1][y] = 2;
				t1--;
				t2++;
			}
			if (y > 0 && arr[x][y - 1] == 0) {
				temp.push({ x , y - 1 });
				arr[x ][y-1] = 2;
				t1--;
				t2++;
			}
			if (y < m - 1 && arr[x][y + 1] == 0) {
				temp.push({ x, y + 1 });
				arr[x][y + 1] = 2;
				t1--;
				t2++;
			}
		}
		//cout << date<<"///"<<t0<<" " << t1 << " " << t2 << endl;
		if (temp.empty() == 1 && num != t0 + t2) {
			date = -1;
			return;
		}
		else if (temp.empty() == 1 && num == t0 + t2) {
			date--;
			return;
		}
		while (temp.empty() == 0) {
			q.push({ temp.front().first, temp.front().second });
			temp.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j;
	cin >> m >> n;
	num = n * m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) t0++;
			else if (arr[i][j] == 0) t1++;
			else {
				q.push({ i, j });
				t2++;
			}
		}
	}
	if (num == t0 + t2) {
		cout << "0";
		return 0;
	}
	bfs();
	cout << date;
}