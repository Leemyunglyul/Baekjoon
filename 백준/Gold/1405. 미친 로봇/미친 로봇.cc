#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

int act;
double e, w, n, s;
double sum = 0;
vector<pair<int, int>> way;
vector<double> dir;

void dfs(int now) {
	int i, j, x ,y ;
	double temp;
	if (now == act) {
		for (i = 1, temp=1; i <= act; i++) {
			temp *= dir[i];
		}
		sum += temp;
		dir.pop_back();
		way.pop_back();
		return;
	}
	for (i = 1; i <= 4; i++) {
		if (i == 1) {
			x = way[now].first+1;
			y = way[now].second;
			temp = e;
		}
		else if (i == 2) {
			x = way[now].first - 1;
			y = way[now].second;
			temp = w;
		}
		else if (i == 3) {
			x = way[now].first;
			y = way[now].second-1;
			temp = s;
		}
		else if (i == 4) {
			x = way[now].first;
			y = way[now].second + 1;
			temp = n;
		}
		for (j = 0; j < now; j++) {
			if (x == way[j].first && y == way[j].second) break;
		}
		if (now==0 ||j == now) {
			way.push_back({ x, y });
			dir.push_back(temp);
			dfs(now + 1);
		}
	}
	dir.pop_back();
	way.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> act >> e >> w >> s >> n;
	e = 0.01 * e;
	w = 0.01 * w;
	n = 0.01 * n;
	s = 0.01 * s;
	way.push_back({ 0, 0 });
	dir.push_back(0);
	dfs(0);
	cout << fixed;
	cout.precision(9);
	cout << sum;
}