#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> arr;
int n, m;
int parent[100100];

int find(int a) {
	if (a==parent[a]) return a;
	else return parent[a]=find(parent[a]);
}

bool sameparent(int a, int b) {
	if (find(a) == find(b)) return true;
	else return false;
}

void unionn(int a, int b) {
	a = find(a);
	b = find(b);
	if(find(a)!=find(b)) parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, a, b, c, sum, x;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr.push_back({ c, {a, b} });
	}
	sort(arr.begin(), arr.end());
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (i = 0, sum=0, x=0; i <m; i++) {
		if (!sameparent(arr[i].second.first, arr[i].second.second)) {
			unionn(arr[i].second.first, arr[i].second.second);
			sum += arr[i].first;
			x = arr[i].first;
		}
	}
	cout << sum-x;
}