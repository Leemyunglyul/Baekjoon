#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int parent[10010];
int nation[10010];
vector<pair<int, pair<int, int>>> list;

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
	if(x!=y) parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, p, q, s, e, l, i, sum, mint;
	cin >> n >> p;
	for (i = 1, mint=10000; i <= n; i++) {
		parent[i] = i;
		cin >> nation[i];
		mint = min(mint, nation[i]);
	}
	for (i = 0; i < p; i++) {
		cin >> s >> e >> l;
		list.push_back({ (2*l)+nation[s]+nation[e], {s, e}});
	}
	sort(list.begin(), list.end());
	for (i = 0, sum=0; i < p; i++) {
		s = list[i].second.first;
		e = list[i].second.second;
		if (!sameparent(s, e)) {
			unionn(s, e);
			sum += list[i].first;
			//cout << list[i].first << "//\n";
		}
	}
	cout << sum+mint;
}