#include<iostream>
#include<math.h>
#include<stack>
#include<queue>

using namespace std;

priority_queue<int> big;

int rev(int x) {
	int num = 0;
	stack<int> st;
	while (x > 0) {
		st.push(x % 10);
		x = (x - x % 10)/10;
	}
	int dec = 1;
	while (!st.empty()) {
		num += st.top() * dec;
		st.pop();
		dec *= 10;
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, i;
	cin >> n >> k;
	for (i = 1; i <= k; i++) {
		big.push(rev(n * i));
	}
	cout << big.top();
}