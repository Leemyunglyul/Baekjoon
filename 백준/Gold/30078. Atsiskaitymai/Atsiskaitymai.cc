#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

priority_queue <int, vector<int>, greater<int>> now;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, t1, t2, dup;
	cin >> n;
	for (i = 0, dup=0; i < n; i++) {
		cin >> t1 >> t2;
		pq.push({ t1, t2 });
	}
	while (!pq.empty()) {
		t1 = pq.top().first;
		t2 = pq.top().second;
		pq.pop();
		if (now.empty()) {
			now.push(t2);
		}
		else {
			while (!now.empty() && t1 >= now.top()) now.pop();
			now.push(t2);
		}
		dup = max(dup, int(now.size()));
	}
	cout << dup;
}