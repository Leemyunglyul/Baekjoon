#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

vector <pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t1, t2, start, end, a, b1, b2;
	cin >> start >> end >> t1 >> t2;
	a = max(start, end) - min(start, end);
	b1 = max(max(start, end), max(t1, t2)) - min(max(start, end), max(t1, t2));
	b2= max(min(start, end), min(t1, t2)) - min(min(start, end), min(t1, t2));
	cout << min(a, b1 + b2);
}