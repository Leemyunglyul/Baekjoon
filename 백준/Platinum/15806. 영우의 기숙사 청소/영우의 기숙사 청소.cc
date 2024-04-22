#define MP(x,y) make_pair(x,y)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, T;
queue<pair<int, int>> que;
bool odd[301][301];
bool even[301][301];

int dr[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dc[8] = { 2,1,-1,-2,-2,-1,1,2 };

void oddbfs() {
	int rep = que.size();
	while (rep--) {
		auto& p = que.front();
		int r = p.first, c = p.second;
		que.pop();
		for (int i = 0; i < 8; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (rr<1 || rr>N || cc<1 || cc>N) continue;
			if (odd[rr][cc]) continue;
			odd[rr][cc] = 1;
			que.push(MP(rr, cc));
		}
	}
}

void evenbfs() {
	int rep = que.size();
	while (rep--) {
		auto& p = que.front();
		int r = p.first, c = p.second;
		que.pop();
		for (int i = 0; i < 8; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (rr<1 || rr>N || cc<1 || cc>N) continue;
			if (even[rr][cc]) continue;
			even[rr][cc] = 1;
			que.push(MP(rr, cc));
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K >> T;;
	while (M--) {
		int r, c; cin >> r >> c;
		que.push(MP(r, c));
	}
	for (int t = 1; t <= T; t++) {
		if (t & 1) oddbfs();
		else evenbfs();
	}

	bool ans = 1;
	while (K--) {
		int r, c; cin >> r >> c;
		if (T & 1) {
			if (odd[r][c]) ans = 0;
		}
		else {
			if (even[r][c]) ans = 0;
		}
	}

	if (ans) cout << "NO";
	else cout << "YES";
}