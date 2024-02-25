#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;
int n[110][110];
int r[110][110];

int sizee, lamp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, pre, possible, k;
	cin >> sizee >> lamp;
	for (i = 0; i < sizee; i++) {
		for (j = 0; j < sizee; j++) {
			cin >> n[i][j];
			r[j][i] = n[i][j];
		}
	}
	for (i = 0, possible = 0; i < sizee; i++) {//세로로.
		queue<int> q;
		for (j = 0, pre=0 ; j < sizee; j++) {
			if (q.empty() || r[i][j]==q.front()) {
				q.push(r[i][j]);
			}
			else if (r[i][j] > q.front() + 1 || r[i][j] < q.front() - 1) break;
			else if (r[i][j] == q.front() + 1) {
				if (lamp <= q.size()-pre) {
					while (!q.empty()) q.pop();
					q.push(r[i][j]);
					pre = 0;
				}
				else break;
			}
			else if (r[i][j] == q.front() - 1) {
				for (k = 1; k < lamp; k++) if (r[i][j + k] != q.front() - 1) break;
				if (k == lamp) {
					while (!q.empty()) q.pop();
					q.push(r[i][j]);
					pre = 1;
					j = j + lamp - 1;
				}
				else break;
			}
		}
		if (j == sizee) possible++;
		//cout<<"세로 "<< i <<" " << possible << endl;
	}
	for (i = 0; i < sizee; i++) {//가로로.
		queue<int> q;
		for (j = 0, pre=0; j < sizee; j++) {
			if (q.empty() || n[i][j] == q.front()) {
				q.push(n[i][j]);
			}
			else if (n[i][j] > q.front() + 1 || n[i][j] < q.front() - 1) break;
			else if (n[i][j] == q.front() + 1) {
				if (lamp <= q.size()-pre) {
					while (!q.empty()) q.pop();
					q.push(n[i][j]);
					pre = 0;
				}
				else break;
			}
			else if (n[i][j] == q.front() - 1) {
				for (k = 1; k < lamp; k++) if (n[i][j + k] != q.front() - 1) break;
				if (k == lamp) {
					while (!q.empty()) q.pop();
					q.push(n[i][j]);
					pre = 1;
					j = j + lamp - 1;
				}
				else break;
			}
		}
		if (j == sizee) possible++;
		//cout << "가로 " << i << " " << possible << endl;
	}
	cout << possible;
}