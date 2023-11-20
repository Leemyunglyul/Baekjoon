#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
//#include <deque>
//#include <algorithm>

using namespace std;
long long int arr[5000002];
long long int mem[5000002];
priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
priority_queue<long long int, vector<long long int>, greater<long long int>> trash;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l, i;
	cin >> n >> l;
	for (i = 0; i < n; i++) cin >> arr[i];
	for (i = 0; i < n; i++) {
		if (i >= l) {
			trash.push(arr[i - l]);
		}
		if (pq.empty() == 1 || pq.size() < l);
		else if (pq.size()>=l) {
			while (trash.empty()==0 && trash.top() == pq.top()) {
				pq.pop();
				trash.pop();
			}
		}
		pq.push(arr[i]);
		mem[i] = pq.top();
	}
	for (i = 0; i < n; i++) {
		cout << mem[i] << " ";
	}
}