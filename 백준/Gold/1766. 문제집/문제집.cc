#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> link;
vector<int> temp;
int arr[100100] = {0};
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, j, x, y;
	cin >> n >> m;
	for (i = 0; i <= n; i++) {
		temp.push_back(0);
		link.push_back(temp);
		temp.clear();
	}
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		arr[y]++;
		link[x].push_back(y);
	}
	for (i = 1; i <=n; i++) {
		if (arr[i] == 0) pq.push(i);
	}
	int num = 0;
	while (num < n) {
		x = pq.top();
		pq.pop();
		cout << x << " ";
		num++;
		for (i = 1; i < link[x].size(); i++) {
			arr[link[x][i]]--;
			if (arr[link[x][i]] == 0) pq.push(link[x][i]);
		}
	}
}