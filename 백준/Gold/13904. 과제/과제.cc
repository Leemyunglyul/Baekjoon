#include<iostream>
#include<math.h>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<pair<int, int>> hw;
priority_queue<pair<int, int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, due, score, day, sum, check;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> due >> score;
		hw.push_back({ due, score });
	}
	sort(hw.begin(), hw.end());
	pq.push({hw[n-1].second, -hw[n-1].first});
	day = hw[n-1].first;
	sum = 0;
	check = n-2;
	while (day>0) {
		while (check>=0 && hw[check].first >= day) { 
			pq.push({ hw[check].second, -hw[check].first });
			check--;
		}
		if (!pq.empty()) {
			//cout << pq.top().first << endl;
			sum += pq.top().first;
			pq.pop();
		}
		day--;
	}
	cout << sum;
}