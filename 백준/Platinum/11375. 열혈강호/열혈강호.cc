#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int cow[1010], shed[1010];
vector<int> adj[1010];
bool visited[1010];

bool dfs(int from) {
	visited[from] = true;
	for (int i = 0; i < adj[from].size(); i++) {
		int to = adj[from][i];
		if (shed[to] == -1 || (!visited[shed[to]] && dfs(shed[to]))) {
			cow[from] = to;
			shed[to] = from;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, from, to, num, i, x;
	cin >> n >> m;
	for (from = 1; from <= n; from++) {
		cin >> num;
		for (i = 0; i < num; i++) {
			cin >> x;
			adj[from].push_back(x);
		}
	}
	int match = 0;
	fill(&cow[1], &cow[n + 1], -1);
	fill(&shed[1], &shed[m + 1], -1);
	for (i = 1; i <= n; i++) {
		if (cow[i] == -1) {
			fill(&visited[1], &visited[n + 1], false);
			if (dfs(i)) match++;
		}
	}
	cout << match;
}