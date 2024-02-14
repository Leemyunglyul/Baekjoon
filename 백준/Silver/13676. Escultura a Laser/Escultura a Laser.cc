#include<iostream>
#include<math.h>
#include<stack>
#include<algorithm>

using namespace std;

stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int row, col, i, x, j, sum, temp;
	while (1) {
		cin >> row >> col;
		if (row == 0 && col == 0) break;
		for (i = 0, sum=0; i < col; i++) {
			cin >> x;
			if (st.empty()) {
				st.push(x);
				sum += row - x;
				continue;
			}
			if (st.top() <= x);
			else sum += st.top()-x;
			st.push(x);
		}
		while (!st.empty()) st.pop();
		cout << sum << "\n";
	}
}