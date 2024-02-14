#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

int arr[300100];
queue<int> od;
queue<int> ev;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, et, ot;
	cin >> n;
	for (i = 0; i < n; i++) cin >> arr[i];
	for (i = 0; i < n; i++) {
		if (od.empty() && arr[i] % 2 == 1) od.push(arr[i]);
		else if (od.empty());
		else if (od.back() % 2 == 0 && arr[i] % 2 == 1) od.push(arr[i]);
		else if (od.back() % 2 == 1 && arr[i] % 2 == 0) od.push(arr[i]);
		else;
		
		if (ev.empty() && arr[i] % 2 == 0) ev.push(arr[i]);
		else if (ev.empty());
		else if (ev.back() % 2 == 0 && arr[i] % 2 == 1) ev.push(arr[i]);
		else if (ev.back() % 2 == 1 && arr[i] % 2 == 0) ev.push(arr[i]);
		else;
	}
	cout << max(od.size(), ev.size());
}