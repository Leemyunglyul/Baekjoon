#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
queue <int> p1;
queue <int> p2;

int arr[100];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, i, sum, num1, j, num2;
	cin >> n;
	for (i = 0, sum=0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (i = 0, num1=0, num2=0; i < n; i++) {
		if (arr[i] < 0) {
			p1.push(arr[i]);
		}
		else if (arr[i] == 0) {
			num1++;
		}
		else if (arr[i] == 1) num2++;
		else break;
	}
	for (j = n-1; j>=i; j--) {
		p2.push(arr[j]);
	}
	while (p1.empty() == 0) {
		if (p1.size() == 1) {
			if (num1 == 0) sum += p1.front();
			p1.pop();
		}
		else {
			i = p1.front();
			p1.pop();
			j = p1.front();
			p1.pop();
			sum += i * j;
		}
	}
	while (p2.empty() == 0) {
		if (p2.size() == 1) {
			sum += p2.front();
			p2.pop();
		}
		else {
			i = p2.front();
			p2.pop();
			j = p2.front();
			p2.pop();
			sum += i * j;
		}
	}
	sum += num2;
	cout << sum;
}