#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

priority_queue <int> a, b;

int main() {
	int n, sum, i, x, y;
	cin >> n;
	for (sum=0,i = 0; i < n; i++) {
		cin >> x;
		a.push(x);
	}
	for (i = 0; i < n; i++) {
		cin >> y;
		b.push(100 - y);
	}
	for (i = 0; i < n; i++) {
		sum += a.top() * (100 - b.top());
		a.pop();
		b.pop();
	}
	cout << sum;
}