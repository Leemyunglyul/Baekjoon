#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
//#include <algorithm>

using namespace std;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum, i, now, next, temp;
	string x;
	cin >> x;
	if (x.size() % 2 == 1) {
		cout << "0";
		return 0;
	}
	for (i = 0, sum=0, now=0, temp=0; i < x.size(); i++, now=0, temp=0) {
		//cout << x[i];
		if (x[i] == '(') now = -1;
		else if (x[i] == ')') now = -2;
		else if (x[i] == '[') now = -3;
		else if (x[i] == ']') now = -4;
		if (st.empty() == 1) {
			st.push(now);
			continue;
		}
		if (st.empty()==0 && st.top() >= 0) {
			temp = st.top();
			st.pop();
			if (st.empty()==0 &&((st.top() == -1 && now == -2) || (st.top() == -3 && now == -4)));
			else st.push(temp);
		}
		if (st.empty()==0 && st.top() == -1 && now==-2) {
			st.pop();
			if (temp == 0) temp = 2;
			else temp *= 2;
			while (st.empty()==0 &&st.top() >= 0) {
				temp += st.top();
				st.pop();
			}
			st.push(temp);
			continue;
		}
		else if (st.empty() == 0 &&  st.top() == -3 && now == -4) {
			st.pop();
			if (temp == 0) temp = 3;
			else temp *= 3;
			while (st.empty() == 0 &&  st.top() >= 0) {
				temp += st.top();
				st.pop();
			}
			st.push(temp);
			continue;
		}
		else if (st.empty()==0&&((st.top() == -3 && now == -2) || (st.top() == -1 && now == -4))) {
			cout << "0";
			return 0;
		}
		else st.push(now);
	}
	temp = st.top();
	st.pop();
	if (st.empty() == 0) {
		cout << "0";
		return 0;
	}
	cout << temp;
}