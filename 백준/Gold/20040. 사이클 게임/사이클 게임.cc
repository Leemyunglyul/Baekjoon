#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<pair<int, int>> arr;
int n, m;
int parent[500100];

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

bool sameparent(int a, int b) {
	if (find(a) == find(b)) return true;
	else return false;
}

void unionn(int a, int b) {
	a = find(a);
	b = find(b);
	if (find(a) != find(b)) parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, a, b, c, sum, x;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		arr.push_back( {a, b});
	}
	for (i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (i = 0, sum = 0, x = -1; i < m; i++) {
		if (!sameparent(arr[i].first, arr[i].second)) {
			unionn(arr[i].first, arr[i].second);
			x = i;
		}
		else break;
	}
	if (i == m) cout << "0";
	else cout << i+1;
}