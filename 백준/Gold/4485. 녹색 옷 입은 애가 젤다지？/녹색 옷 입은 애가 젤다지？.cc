#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dp[126][126];
vector<pair<int, int>> node[18000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, num;
	num = 0;
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		int value, i, j;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++) {
				node[i * n + j].clear();
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dp[i][j] = 180000;
				cin >> value;
				if (i == 0 && j == 0) {
					dp[0][0] = value;
				}
				if (i > 0) node[(i - 1) * n + j].push_back({value, i*n+j});
				if(j>0) node[i* n + j-1].push_back({ value, i * n + j });
				if(i<n-1)node[(i + 1) * n + j].push_back({ value, i * n + j });
				if (j<n-1)node[i * n + j+1].push_back({ value, i * n + j });
			}
		}

		pq.push({ dp[0][0], 0});
		while (!pq.empty()) {
			int dis = pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (i = 0; i < node[pos].size(); i++) {
				int next = node[pos][i].second;
				int costt = node[pos][i].first;

				int row = next / n;
				int col = next % n;

				if (dp[row][col] > dis + costt) {
					dp[row][col] = dis + costt;
					pq.push({ dp[row][col], next });
				}
			}
		}
		cout << "Problem " << ++num << ": " << dp[n - 1][n - 1] << "\n";
	}
}