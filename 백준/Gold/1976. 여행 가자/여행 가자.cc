#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int arr[210][210] = { 0 };
int n, m;
int trip[1010];

void graph(int start,int num) {
	int i;
	for (i = 1; i <= n; i++) {
		if (i == num|| arr[num][i]==0 || (arr[start][i] && arr[num][i])) continue;
		if (arr[num][i]) {
			arr[start][i] = 1;
			if (i != start) graph(start, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, k, x, y;
	cin >> n >> m;
	for (i = 1; i <=n ; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 1; i <= m; i++) {
		cin >> trip[i];
	}
    if (m <=1) {
		cout << "YES";
		return 0;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (j == i) continue;
			if (arr[i][j] == 1) graph(i, j);
		}
	}
    for (i = 1; i <= n; i++) arr[i][i] = 1;
	for (i = 1; i < m; i++) {
		if (arr[trip[i]][trip[i + 1]] == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}