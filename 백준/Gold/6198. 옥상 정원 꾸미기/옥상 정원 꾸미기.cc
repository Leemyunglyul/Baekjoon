#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
stack <pair<long long int, long long int>> st;
long long int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long int n, i, sum;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		if (st.empty() == 1);
		else {
			while (st.empty()==0 && st.top().first <= arr[i]) {
				if (st.top().first <= arr[i]) {
					arr[st.top().second] = i - st.top().second-1;
				}
				st.pop();
			}
		}
		st.push({ arr[i], i });
	}
	while (st.empty() == 0) {
		arr[st.top().second] = n - 1 - st.top().second;
		st.pop();
	}
	for (i = 0, sum=0; i < n; i++) {
		sum += arr[i];
		//cout << i << " " << arr[i] << endl;
	}
	cout << sum;
}