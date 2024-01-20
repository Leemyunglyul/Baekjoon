#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<queue>
//#include<deque>
//#include<string.h>
#include<math.h>
#include<cmath>
#include<map>
#include<algorithm>
//#include<functional>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y;
	double a, b;
	cin >> x >> y;
	a = double(x + y) / 2;
	b = double(x - y) / 2;
	if (x < y || a != (x + y) / 2 || b != (x - y) / 2) {
		cout << "-1";
	}
	else {
		cout << max(a,b) << " " << min(a,b);
	}
}