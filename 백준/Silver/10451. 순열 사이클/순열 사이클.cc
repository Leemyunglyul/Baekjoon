#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<queue>
//#include<deque>
//#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
//#include<functional>

using namespace std;

int arr[1001] = {0};
vector<int> v;

void cycle(int p, int end) {
	if (arr[p] == end);
	else cycle(arr[p], end);
	arr[p] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, n, i, x, num;
	cin >> test;
	while (test--) {
		cin >> n;
		for (i = 1, num=0; i <= n; i++) {
			cin >> x;
			v.push_back(x);
			arr[i] = x;
		}
		for (i = 1; i <= n; i++) {
			if (arr[i] != 0) {
				cycle(i, i);
				num++;
			}
		}
		cout << num << endl;
	}
}