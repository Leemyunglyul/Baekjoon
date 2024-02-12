#include<iostream>
#include<math.h>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> num;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, index, start, end;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> index >> start >> end;
		pq.push({ start, end });
	}
	while (!pq.empty()) {
		start = pq.top().first;
		end = pq.top().second;
		pq.pop();
		if (num.empty());
		else if (num.top() <= start) num.pop();
		num.push(end);
	}
	cout << num.size();
}