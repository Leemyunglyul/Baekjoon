#include<iostream>
#include<math.h>
#include<string>
#include<stack>
#include<vector>

using namespace std;

stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, era, i, t, num;
	string x;
	cin >> n>>era>>x;
	for (i = 0, num=0; i < n; i++) {
		t = x[i] - 48;
		if (st.empty()) {
			st.push(t);
			continue;
		}
		while (!st.empty() && num<era && st.top() < t) {
			st.pop();
			num++;
		}
		st.push(t);
	}
	while (num < era) {
		st.pop();
		num++;
	}
	vector<int> print;
	while (!st.empty()) {
		print.push_back(st.top());
		st.pop();
	}
	for (i = print.size() - 1; i >= 0; i--) {
		cout << print[i];
	}
}