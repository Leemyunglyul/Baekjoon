#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

vector<pair<int, int>> rev;
long long int boom_num[4] = { 0 };
int n, arr[53][53], magic;
int tx[53][53];
int line[2600];

void boom() {
	vector<int> x;
	int i, branch;
	for (i = 1; i <= n * n - 1; i++) {
		branch = i + 1;
		if (line[i] == 0) {
			x.push_back(0);
			if (x.size() == n * n - 1) break;
			continue;
		}
		if (i <= n * n - 2 && line[i] == line[i + 1]) {
			while (branch<=n*n-1 && line[i] == line[branch]) branch++;
			
		}
		int num = branch - i ;
		x.push_back(num);
		if (x.size() == n * n - 1) break;
		x.push_back(line[i]);
		if (x.size() == n * n - 1) break;
		i = branch - 1;
	}
	for (i = 0; i < x.size(); i++) {
		line[i + 1] = x[i];
	}
	x.clear();
}

void refill() {
	int i, now;
	int temp[2600] = {0};
	for (i = 1; i <= n * n - 1; i++) {
		temp[i] = line[i];
		line[i] = 0;
	}
	for (i = 1, now = 1; i <= n * n - 1; i++) {
		if (temp[i] == 0) continue;
		line[now++] = temp[i];
	}
}

void destroy() {
	int i, branch, j, k, retry;
	for (i = 1, retry=0; i <= n * n - 1; i++) {
		if (line[i] == 0) continue;
		if (i <= n * n - 4 && line[i] == line[i + 1]) {
			branch = i+1;
			while (branch<=n*n-1 && line[i] == line[branch]) branch++;
			if (branch - i >= 4) {
				retry = 1;
				boom_num[line[i]] += branch - i;
				for (j = i; j < branch; j++) line[j] = 0;
			}
			i = branch - 1;
		}
	}
	if (retry == 1) {
		refill();
		destroy();
	}
}

void shark_magic(int d, int s) {//상하좌우
	int x = (n + 1) / 2;
	int y = x;
	int i;
	if (d == 1) {//상
		for (i = 1; i <= s; i++) {
			line[tx[x-i][y]] = 0;
		}
	}
	else if (d == 2) {//하
		for (i = 1; i <= s; i++) {
			line[tx[x + i][y]] = 0;
		}
	}
	else if (d == 3) {//좌
		for (i = 1; i <= s; i++) {
			line[tx[x][y-i]] = 0;
		}
	}
	else if (d == 4) {//우
		for (i = 1; i <= s; i++) {
			line[tx[x][y + i]] = 0;
		}
	}
	refill();
}

void record() {
	int i, j;
	int r = (n + 1) / 2 ;
	int c = (n + 1) / 2 - 1;
	int dir = 2;
	rev.push_back({ (n + 1) / 2,(n + 1) / 2 });
	int wall[5] = {0,  (n+1)/2 - 1, (n + 1) / 2 + 1 ,(n + 1) / 2 - 2, (n + 1) / 2 + 1 };
	for (i = 1; i <= n * n - 1; i++) {
		rev.push_back({ r, c });
		tx[r][c] = i;

		if (dir == 1) {
			r--;
			if (r == wall[dir]) {
				wall[dir]--;
				dir = 3;
			}
		}
		else if (dir == 2) {
			r++;
			if (r == wall[dir]) {
				wall[dir]++;
				dir = 4;
			}
		}
		else if (dir == 3) {
			c--;
			if (c == wall[dir]) {
				wall[dir]--;
				dir = 2;
			}
		}
		else if (dir == 4) {
			c++;
			if (c == wall[dir]) {
				wall[dir]++;
				dir = 1;
			}
		}
	}
}

void rearr() {
	//cout << rev.size() << endl;
	for (int i = 1; i <= n * n - 1; i++) {
		arr[rev[i].first][rev[i].second] = line[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> magic;
	int i, j, d, s;
	record();
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
			line[tx[i][j]] = arr[i][j];
		}
	}
	for (i = 0; i < magic; i++) {
		cin >> d >> s;//상하좌우
		shark_magic(d, s);
		
		destroy();
		boom();
		//cout << rev.size() << endl;
		rearr();
	}
	cout << boom_num[1] + boom_num[2] * 2 + boom_num[3] * 3;
}