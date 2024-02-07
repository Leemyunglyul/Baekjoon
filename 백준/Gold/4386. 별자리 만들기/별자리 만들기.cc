#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<double, double>> pos;
vector<pair<double, pair<int, int>>> mst;
int parent[110];

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) return false;
	else return true;
}

void unionn(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y)	parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double x, y, d, x2, y2, x1, y1;
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		parent[i] = i;
		cin >> x >> y;
		pos.push_back({ x, y });
	}
	for (i = 0; i < n; i++) {
		x1 = pos[i].first;
		y1 = pos[i].second;
		for (j = i + 1; j < n; j++) {
			x2 = pos[j].first;
			y2 = pos[j].second;
			d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			mst.push_back({ d, {i, j} });
		}
	}
	sort(mst.begin(), mst.end());
	double sum = 0;
	for (i = 0; i < mst.size(); i++) {
		x = mst[i].second.first;
		y = mst[i].second.second;
		if (!sameparent(x, y)) {
			unionn(x, y);
			sum += mst[i].first;
		}
	}
	cout << sum;
}