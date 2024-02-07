#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
vector<int> graph;
int visited[100100] = {0};
vector<int> temp;

int dfs(int now) {
	int i;
	temp.push_back(now);
	
	if (visited[graph[now]] == 1) {
		for (i = 0; i < temp.size(); i++) {
			if (temp[i] == graph[now]) {
				//cout << "asdf<<" << temp.size() - i << endl;
				return temp.size()-i;
			}
		}
		return 0;
	}

	visited[now] = 1;
	return dfs(graph[now]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, n, i, j, sum, x;
	cin >> testn;
	while (testn--) {
		cin >> n;
		graph.push_back(0);
		for (i = 1, sum=0; i <= n; i++) {
			visited[i] = 0;
			cin >> x;
			graph.push_back(x);
			if (x == i) {
				sum++;
				visited[i] = 1;
			}
		}
		for (i = 1; i <= n; i++) {
			//cout << sum << " ";
			if (visited[i] == 1) continue;
			sum += dfs(i);
			temp.clear();
		}
		//cout << endl;
		graph.clear();
		cout << n-sum << "\n";
	}
}