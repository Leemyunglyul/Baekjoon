#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
int arr[1000010];
deque<int> action;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int tn, n, i, sum, stock, num, j;
	cin >> tn;
	while (tn--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (i = 0; i < n; i++) {
			if (action.empty() == 1);
			else if (action.back() < arr[i]) {
				while (action.empty() == 0 && action.back() < arr[i]) {
					action.pop_back();
				}
			}
			action.push_back(arr[i]);
		}
		for (i = 0, sum=0, stock=0, num=0; action.empty()==0; i++) {
			//cout << action.front() << " ";
			if (arr[i] != action.front()) {
				stock += arr[i];
				num++;
			}
			else if (stock == 0) {
				action.pop_front();
			}
			else {
				sum += action.front() * num - stock;
				stock = 0;
				num=0;
				action.pop_front();
			}
		}
		cout << sum << endl;
	}
}