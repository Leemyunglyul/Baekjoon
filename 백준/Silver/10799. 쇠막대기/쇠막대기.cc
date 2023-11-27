#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
//#include <algorithm>

using namespace std;
stack<long long int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x, y;
	long long int i, sum, now, pre;
	cin >> x;
	for (i = 0, sum=0, now=0; i < x.size(); i++) {
		if (x[i] == '(') pre = -1;
		else if (x[i] == ')') pre = -2;
		if (st.empty() == 1) {
			st.push(pre);
			if (x[i + 1] == '(') {
				now++;
				sum++;
			}
		}
		else if (st.top() == -1 && pre==-2) {
			st.pop();
			st.push(now);
			sum += now;
		}
		else if(st.top()!=-1 && pre==-2) {
			st.push(pre);
			now--;
		}
		else if (pre == -1) {
			st.push(pre);
			if (x[i + 1] == '(') {
				now++;
				sum++;
			}
		}
		//cout<<x[i] << now << endl;
	}
	cout << sum;
}