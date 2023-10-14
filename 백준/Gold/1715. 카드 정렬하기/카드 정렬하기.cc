#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<int , vector<int>, greater<int >> q;

int main() {
	unsigned long long int i, x, y,n;
	unsigned long long int sum = 0;
	cin >> n;
	for (i = 1; i <=n; i++) {
		cin >> x;
		q.push(x);
	}
	while (q.empty() == 0) {
		x = q.top();
		q.pop();
		if (q.empty() == 1)
			break;
		y = q.top();
		q.pop();
		sum += x + y;
		q.push(x + y);
	}
	cout << sum;
}