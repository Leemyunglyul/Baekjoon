#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<set>

using namespace std;

map<string, int> pos;
int arr[200100] = { 0 };
int parent[200100];

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, n, i, idx;
	string x, y;
	cin >> testn;
	while (testn--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			parent[i] = i;
			arr[i] = 0;
		}
		for (i = 0, idx=0; i < n; i++) {
			cin >> x >> y;
			if (pos.find(x) == pos.end() && pos.find(y) == pos.end()) {
				pos.insert({x, idx});
				pos.insert({ y, idx});
				arr[idx++] = 2;
			}
			else if (pos.find(x) != pos.end() && pos.find(y) == pos.end()) {
				pos.insert({ y, pos[x] });
				arr[find(pos[x])]++;
			}
			else if (pos.find(x) == pos.end() && pos.find(y) != pos.end()) {
				pos.insert({ x, pos[y]});
				arr[find(pos[y])]++;
			}
			else {
				if (find(pos[x]) != find(pos[y])) {
					arr[find(pos[x])] += arr[find(pos[y])];
					parent[find(pos[y])] = find(pos[x]);
				}
			}
			cout << arr[find(pos[x])] << "\n";
		}
		pos.clear();
	}
}