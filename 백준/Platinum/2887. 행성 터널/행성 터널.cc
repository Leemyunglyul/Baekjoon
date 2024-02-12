#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100100];
int planet[100100][3];
vector<pair<int, pair<int, int>>> edge;
vector<pair<int, int>> px;
vector<pair<int, int>> py;
vector<pair<int, int>> pz;

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

void unionn(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, i, j, sum;

	cin >> n;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
		cin >> planet[i][0] >> planet[i][1] >> planet[i][2];
		px.push_back({ planet[i][0], i });
		py.push_back({ planet[i][1], i });
		pz.push_back({ planet[i][2], i });
    }
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	sort(pz.begin(), pz.end());
	for (i = 0; i < n-1; i++) {
		edge.push_back({ px[i + 1].first - px[i].first,{ px[i].second, px[i + 1].second} });
		edge.push_back({ py[i + 1].first - py[i].first,{ py[i].second, py[i + 1].second} });
		edge.push_back({ pz[i + 1].first - pz[i].first,{ pz[i].second, pz[i + 1].second} });
	}
	sort(edge.begin(), edge.end());
	for (i = 0, sum=0; i < edge.size(); i++) {
		int p1 = edge[i].second.first;
		int p2 = edge[i].second.second;
		int d = edge[i].first;

		if (!sameparent(p1, p2)) {
			unionn(p1, p2);
			sum += d;
		}
	}
	cout << sum;
}