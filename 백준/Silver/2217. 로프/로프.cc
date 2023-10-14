#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<int> a;

int arr[100001];

int main() {
	int max, i, n, x;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;
		a.push(x);
	}
	for (i = 0; i < n; i++) {
		arr[i] = a.top();
		a.pop();
	}
	for (max=0,i = 0; i < n; i++) {
		max = arr[i] * (i + 1) > max ? (arr[i] * (i + 1)) : max;
	}
	cout << max;
}