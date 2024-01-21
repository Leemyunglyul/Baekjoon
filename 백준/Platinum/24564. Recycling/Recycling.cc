#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
//#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>
//#include<functional>

using namespace std;

int arr[100100] = {0};
stack <int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, maxx, start, end, i, check;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (i = 1, maxx=0; i <= n; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			check = st.top();
			st.pop();
			if (st.empty() && maxx <= (i - 1) * arr[check]) {
				start = 1;
				end = i - 1;
				maxx = (i - 1) * arr[check];
			}
			else if (st.empty()) break;
			else if (maxx < (i - st.top() - 1) * arr[check]) {
				start = st.top() + 1;
				end = i - 1;
				maxx = (i - st.top() - 1) * arr[check];
			}
			else if (maxx < (i - st.top() - 1) * arr[check] && start>st.top()+1) {
				start = st.top() + 1;
				end = i - 1;
				maxx = (i - st.top() - 1) * arr[check];
			}
		}
		st.push(i);
	}
	while (!st.empty()) {
		check = st.top();
		st.pop();
		if (st.empty() && maxx <= n * arr[check]) {
			start = 1;
			end = n;
			maxx = n * arr[check];
		}
		else if (st.empty()) break;
		else if (maxx < (n - st.top()) * arr[check]) {
			start = st.top() + 1;
			end = n;
			maxx = (n - st.top()) * arr[check];
		}
		else if (maxx == (n - st.top()) * arr[check] && st.top()+1<start) {
			start = st.top() + 1;
			end = n;
			maxx = (n - st.top()) * arr[check];
		}
	}
	cout << start << " " << end << " " << maxx;
}