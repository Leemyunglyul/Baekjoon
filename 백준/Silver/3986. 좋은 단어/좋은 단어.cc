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
	string x;
	long long int i, sum, now, pre, n;
	cin >> n;
	sum = 0;
	while (n--) {
		cin >> x;
		for (i = 0; i< x.size(); i++) { 
			if (st.empty() == 1) {
				st.push(x[i] - 65);
			}
			else if (x[i]-65 == st.top()) {
				st.pop();
			}
			else st.push(x[i] - 65);
		}
		if (st.empty() == 1) sum++;
		else {
			while (st.empty() == 0) {
				st.pop();
			}
		}
	}
	cout << sum;
}