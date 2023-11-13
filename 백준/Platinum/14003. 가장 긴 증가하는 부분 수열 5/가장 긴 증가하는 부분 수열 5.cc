#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;
long long int arr[1000001] = { 0 };
long long int d[1000001] = { 0 };
long long int mem[1000001] = { 0 };
stack<long long int> st;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	long long int n, i, size, start, end, mid, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (i = 1, size = 0; i <= n; i++) {
		if (size == 0) {
			d[i] = 1;
			mem[++size] = arr[i];
			continue;
		}
		if (arr[i] > mem[size]) {
			d[i] = ++size;
			mem[size] = arr[i];
			continue;
		}
		else if (arr[i] == mem[size]) {
			d[i] = size;
			continue;
		}
		start = 1;
		end = size;
		while (start <= end) {
			mid = (start + end) / 2;
			if (mem[mid] == arr[i]) {
				d[i] = mid;
				break;
			}
			if (mem[mid] > arr[i]) end = mid - 1;
			else start = mid + 1;
		}
		if (d[i] == 0) {
			d[i] = start;
			mem[start] = arr[i];
		}
	}
	cout << size << endl;
	for (i = n, j = size; i >= 1 && j >= 1; i--) {
		if (d[i] == j) {
			st.push(arr[i]);
			j--;
		}
	}
	for (i = 1; i <= size;i++) {
		cout << st.top() << " ";
		st.pop();
	}
}