#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <functional>
//#include <set>
using namespace std;

vector<int> graph[101];
int visited[101] = { 0};
int cnt = 0;
int n, m, r;

void dfs(int r) {
	if (visited[r] == 1) { 
		return;
	}

	visited[r] = 1; 
	cnt++;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n>>m;
	int x, y;
	while (m--) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);

	cout << cnt-1;
}