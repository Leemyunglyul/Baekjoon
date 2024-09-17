#include<iostream>
#include<math.h>
#include<algorithm>
#include<queue>

using namespace std;

pair<int, int> arr[200100];
long long int sum[200100];
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, p, t, least;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> t >> p;
		arr[i] = { t, p };
	}
	sort(arr, arr + n);
	sum[0] = arr[0].second;
	pq.push(arr[0].second);
	for (i = 1; i < n; i++) {
		if (arr[i].second + sum[i - 1] <= arr[i].first) {
			pq.push(arr[i].second);
			sum[i] = sum[i - 1] + arr[i].second;
			continue;
		}
		if (arr[i].second <pq.top()) {
			sum[i] = sum[i - 1] - pq.top() + arr[i].second;
			pq.pop();
			pq.push(arr[i].second);
			continue;
		}
		sum[i] = sum[i - 1];
	}
	cout << pq.size();
}