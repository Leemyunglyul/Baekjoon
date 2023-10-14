#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
priority_queue <int> q;

int main() {
	int i, sum, check;
	char y;
	string x;
	cin >> x;
	for (i = 1, sum=0, check=0; i <= x.size(); i++) {
		q.push(x[i - 1] - 48);
		sum += x[i - 1] - 48;
		if (x[i - 1] - 48 == 0) check = 1;
	}
	if (check==0 || sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	for (i = 1; i <= x.size(); i++) {
		y = q.top() + 48;
		cout << y;
		q.pop();
	}
}