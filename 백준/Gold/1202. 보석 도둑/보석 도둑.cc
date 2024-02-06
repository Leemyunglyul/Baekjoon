#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first < b.first;
		}
	}
};*/

/*bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}*/

vector<pair<long long int, long long int>> arr;
vector<long long int> bag;
priority_queue<long long int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, k, sum, i, weight, value, num, maxx;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> weight >> value;
		arr.push_back({ weight, value });
	}
	for (i = 0; i < k; i++) {
		cin >> weight;
		bag.push_back(weight);
	}
	sort(arr.begin(), arr.end());
	sort(bag.begin(), bag.end());
	for (i = 0, sum = 0, num=0; i < k; i++) {
		while (num < arr.size() && arr[num].first<=bag[i]) {
			pq.push(arr[num++].second);
		}
		if (pq.empty()) continue;
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}