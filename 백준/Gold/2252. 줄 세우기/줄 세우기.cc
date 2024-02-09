#include<iostream>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;

int arr[33000] = {0};
vector<int> print;
vector<vector<int>> nextt;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, x, y;
	cin >> n >> m;
	vector<int> temp;
	temp.push_back(0);
	nextt.push_back(temp);
	for (i = 1; i <= n; i++) {
		nextt.push_back(temp);
	}
	temp.clear();
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		nextt[x].push_back(y);
		arr[y]++;
	}
	for (i = 1; i <= n; i++) {//먼저 서도 되는 친구들
		if (arr[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (i = 1; i < nextt[x].size(); i++) {//위상 정렬 탐색
			arr[nextt[x][i]]--;
			if (arr[nextt[x][i]] == 0) {
				q.push(nextt[x][i]);
			}
		}
		print.push_back(x);
	}
	for (i = 0; i < print.size(); i++) cout << print[i] << " ";
}