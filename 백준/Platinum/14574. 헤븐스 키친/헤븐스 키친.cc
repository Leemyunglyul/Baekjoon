#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int info[1010][2];
vector<pair<long long int, pair<long long int, long long int>>> arr;
vector<pair<int, int>> fight;
int partn, parent[1010], root;
stack<pair<int, int>> st;
int visited[1010] = { 0 };

void dfs(int _root) {
	int i, x, y;
	visited[_root] = 1;
	vector<int> leaf;

	if (fight.empty()) return;

	for (i = 0; i < fight.size(); i++) {
		x = fight[i].first;
		y = fight[i].second;
		if (x == _root) {
			st.push({ x, y });
			leaf.push_back(y);
			fight.erase(fight.begin() + i, fight.begin() + i + 1);
			i--;
		}
		else if (y==_root) {
			st.push({ y, x });
			leaf.push_back(x);
			fight.erase(fight.begin() + i, fight.begin() + i + 1);
			i--;
		}
	}
	for (i = 0; i < leaf.size(); i++) dfs(leaf[i]);
}

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x]=find(parent[x]);
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) return false;
	else return true;
}

void unionn(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) parent[x] = y;
}

long long int rate(int x, int y) {
	return floor((info[x][1]+info[y][1])/abs(info[x][0]-info[y][0]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	long long int i, j, x, y, sum;
	cin >> partn;
	for (i = 1; i <= partn; i++) {
		parent[i] = i;
		cin >> info[i][0] >> info[i][1];
	}
	for (i = 1; i <= partn; i++) {
		for (j = i + 1; j <= partn; j++) {
			arr.push_back({ rate(i, j) ,{i, j} });
		}
	}
	sort(arr.begin(), arr.end());
	for (i = arr.size()-1, sum = 0; i >=0; i--) {
		x = arr[i].second.first;
		y = arr[i].second.second;

		if (!sameparent(x, y)) {
			//cout << x << "vs" << y << endl;
			fight.push_back({ x, y });
			unionn(x, y);
			sum += arr[i].first;
		}
	}
	cout << sum << "\n";
	dfs(parent[partn]);
	while (!st.empty()) {
		cout << st.top().first << " " << st.top().second << "\n";
		st.pop();
	}
}