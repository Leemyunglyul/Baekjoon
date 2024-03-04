#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int land[12][12];
int addn[12][12], n, treen, kyear;
vector<int> tree[150];
vector<pair<int, int>> rev;

int position(int r, int c) {
	return (r - 1) * n + c;
}

void spring_summer() {
	int i, j, rest, r, c;
	pair<int, int> x;
	vector<int> temp;
	for (i = 1; i <= n * n; i++) {
		sort(tree[i].begin(), tree[i].end());
		r = rev[i].first;
		c = rev[i].second;
		for (j = 0, rest=0; j < tree[i].size(); j++) {
			if (land[r][c] >= tree[i][j]) {
				temp.push_back(tree[i][j]+1);
				land[r][c] -= tree[i][j];
			}
			else {
				rest += tree[i][j] / 2;
			}
		}
		for (j = 0, tree[i].clear(); j < temp.size(); j++) {
			tree[i].push_back(temp[j]);
		}
		temp.clear();
		land[r][c] += rest;
	}
}

void new_tree(int r, int c) {
	if (r > 1) {
		tree[position(r - 1, c)].push_back(1);
		if(c<n) tree[position(r - 1, c+1)].push_back(1);
		if(c>1)  tree[position(r - 1, c - 1)].push_back(1);
	}
	if (c > 1) {
		tree[position(r, c-1)].push_back(1);
		if(r<n) tree[position(r +1, c - 1)].push_back(1);
	}
	if (r < n) {
		tree[position(r + 1, c)].push_back(1);
		if(c<n)tree[position(r + 1, c + 1)].push_back(1);
	}
	if (c < n) {
		tree[position(r , c + 1)].push_back(1);
	}
}

void fall_winter() {
	int i, j, r, c;
	for (i = 1; i <= n * n; i++) {
		r = rev[i].first;
		c = rev[i].second;
		for (j = 0; j < tree[i].size(); j++) {
			if (tree[i][j] % 5 == 0) {
				new_tree(r, c);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <=n; j++) {
			land[i][j] += addn[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> treen >> kyear;
	int i, j, r, c, age, sum;
	fill_n(&land[0][0], 12 * 12, 5);
	rev.push_back({ 0, 0 });
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> addn[i][j];
			rev.push_back({ i, j });
		}
	}
	for (i = 0; i < treen; i++) {
		cin >> r >> c >> age;
		tree[position(r, c)].push_back(age);
	}
	while (kyear--) {
		spring_summer();
		fall_winter();
	}
	for (i = 1, sum=0; i <= n*n; i++) {
		sum += tree[i].size();
	}
	cout << sum;
}