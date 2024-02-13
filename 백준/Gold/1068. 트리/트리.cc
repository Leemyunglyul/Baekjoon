#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> node[52];
int visited[52];
int parent[52];

void dfs(int x) {
	visited[x] = 1;
	if (node[x].empty()) return;
	
	int i;
	for (i = 0; i < node[x].size(); i++) {
		dfs(node[x][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, x, j;
	cin >> n;
	int sum = 0;
	for (i = 0; i < n; i++) {
		cin >> parent[i];
		if (parent[i] == -1);
		else node [parent[i]].push_back(i);
	}
	cin >> x;
	for (i = 0; i < node[parent[x]].size(); i++) {
		if (node[parent[x]][i] == x) {
			node[parent[x]].erase(node[parent[x]].begin() + i, node[parent[x]].begin() + i + 1);
			break;
		}
	}
	dfs(x);
	for (i = 0, sum=0; i < n; i++) {
		if (visited[i] == 1) continue;
		if (node[i].empty()) sum++;
	}
	cout << sum;
}