#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;
int inf = 100000000;
int city[510][510];
int dog[510];
int delay[510][510];
int n;
vector<pair<int, int>> v;

void floyd() {
	int m, s, e, k;
	for (k = 1; k <= n; k++) {
		m = v[k - 1].second;
		for (s = 1; s <= n; s++) {
			for (e = 1; e <= n; e++) {
				if (city[s][e] > city[s][m] - delay[s][m] + city[m][e] - delay[m][e] + max(delay[s][e], max(delay[s][m], delay[m][e]))) {
					delay[s][e] = max(delay[s][e], max(delay[s][m], delay[m][e]));
					city[s][e] = city[s][m] - delay[s][m] + city[m][e] - delay[m][e] + delay[s][e];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, c1, c2, dis, road, ques;
	for (i = 1; i <= 500; i++) {
		for (j = 1; j <= 500; j++) {
			city[i][j] = inf;
		}
	}
	cin >> n >> road >> ques;
	for (i = 1; i <= n; i++) {
		cin >> dog[i];
		v.push_back({ dog[i], i });
	}
	sort(v.begin(), v.end());
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			delay[i][j] = max(dog[i], dog[j]);
		}
	}
	for (i = 0; i < road; i++) {
		cin >> c1 >> c2 >> dis;
		city[c1][c2] = min(city[c1][c2], dis + delay[c1][c2]);
		city[c2][c1] = min(city[c2][c1], dis + delay[c2][c1]);
	}
	floyd();
	for (i = 0; i < ques; i++) {
		cin >> c1 >> c2;
		if (city[c1][c2] == inf) cout << "-1\n";
		else if (c1 == c2) cout << dog[c1] << "\n";
		else cout << city[c1][c2] << "\n";
	}
}