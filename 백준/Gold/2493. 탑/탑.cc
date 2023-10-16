#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

stack <pair<int, int>> a;
int arr[500003];

int main() {
	int n, i, x;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x;
		arr[i] = x;
	}
	for (i = n; i >= 1; i--) {
		if (a.empty() == 0) {
			while (a.empty() == 0 && a.top().first < arr[i]) {
				arr[a.top().second] =i;
				a.pop();
			}
		}
		a.push({arr[i], i});
	}
	while (a.empty() == 0) {
		arr[a.top().second] = 0;
		a.pop();
	}
	for (i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
}