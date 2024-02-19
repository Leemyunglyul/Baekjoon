#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int parent[1001000];

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, op, x, y;
	cin >> n >> m;
	for (i = 0; i <= n; i++) parent[i] = i;
	for (i = 0; i < m; i++) {
		cin >> op >> x >> y;
		if (op == 0) {
			if (find(x) != find(y)) {
				parent[find(y)] = find(x);
			}
		}
		else {
			if (find(x) != find(y)) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}